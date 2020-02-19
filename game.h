#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;
#include <SDL2/SDL.h>

#include "draw.h"
#include "map.h"
#include "player.h"

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
public:
    Game();
    ~Game();
    void loop();
    void render();
    void input();
    void update();
};

#endif //GAME_H