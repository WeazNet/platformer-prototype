#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "debug/debug.h"
#include <vector>
using namespace std;

class Player : public Entity {
private:
    int left, right, up, down;
    int mouseX, mouseY;
    SDL_Renderer *ren;
public:
    Player(SDL_Renderer* &r);
    ~Player();
    void input(SDL_Event &e);
    void update();
    void updateMouse(vector<Object> map);
};

#endif//PLAYER_H