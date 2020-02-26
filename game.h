#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "font.h"
#include "draw.h"
#include "map.h"
#include "player.h"
#include "collisions.h"
#include "debug/debug.h"
#include "debug/debugInterface.h"
#include "generate.h"
#include "define.h"

class Game {
private:
    SDL_Window *w;
    SDL_Renderer *ren;
    SDL_Rect rect;
    bool running;
    int mouseX, mouseY;
    Collisions collisions;
    Font font;
    DebugInterface *debugInterface;
    Map *map;
    Draw *draw;
    Player *player;
public:
    Game(SDL_Window* &window, SDL_Renderer* &renderer);
    ~Game();
    void loop();
    void render();
    void input();
    void update();
};

#endif //GAME_H