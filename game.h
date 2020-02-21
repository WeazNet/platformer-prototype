#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "draw.h"
#include "map.h"
#include "player.h"
#include "debugger.h"
#include "utils.h"

#define WIDTH 1280
#define HEIGHT 720

class Game {
private:
    SDL_Window *w;
    SDL_Renderer *ren;
    bool running;
    int lastFrame, frameCount, FPS;
    int mouseX, mouseY;
    Map *map;
    Draw *draw;
    Player *player;
    Debugger *debugger;
    Utils utils;
public:
    Game(SDL_Window* &window, SDL_Renderer* &renderer);
    ~Game();
    void loop();
    void render();
    void input();
    void update();
};

#endif //GAME_H