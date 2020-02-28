#ifndef PLAYER_H
#define PLAYER_H

enum ActionsMouse {
    HOVERED,
    PRESSED,
    STOPPED
};

#include "entity.h"
#include "map.h"
#include "draw.h"
#include "debug/debug.h"
#include <vector>

class Player : public Entity {
private:
    int left, right, up, down;
    SDL_Renderer *ren;
    SDL_Event e;
    Draw* draw;
public:
    Player(SDL_Renderer* &r);
    ~Player();
    void input(SDL_Event &event);
    void tileInteractivity(std::vector<Tile> map);
    void update();
    void onAction(Tile &t, int a);
};

#endif//PLAYER_H