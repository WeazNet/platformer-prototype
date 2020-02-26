#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <tuple>
#include <fstream>
#include <map>

#include "tile.h"
#include "font.h"
#include "debug/debug.h"

class Draw {
private:
    SDL_Renderer* ren;
public:
    Draw(SDL_Renderer* &r);
    ~Draw();
    tuple<int, int, int> initText(const char* text, int x, int y, int r, int g, int b, int a, TTF_Font* font, tuple<int,int,int>origin, Object &parentClass, int spacing = 0);
    tuple<int, int, int> initText(const char* text, int x, int y, int r, int g, int b, int a, TTF_Font* font, tuple<int,int,int>origin);
    void initObject(Object &o, Object const &parentClass, int spacing = 0);
    void initObject(Object &o);
    void initFileConfig(string filename, vector<char>heights, int w, int h, int x=0, int y=0);
    void initFile(Tile &o, string filename);
    void removeFile(const char* filename);
    void initFileSpace(string filename);
};
#endif//DRAW_H