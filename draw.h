#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL_ttf.h>

#include "object.h"

class Draw {
private:
    TTF_Font* font;
    SDL_Renderer* ren;
public:
    Draw(SDL_Renderer* r);
    ~Draw();
    void init(const char* text, int x, int y, int r, int g, int b, int a);
    void init(Object o);
};

#endif