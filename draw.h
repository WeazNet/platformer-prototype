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
    std::tuple<int, int, int> initText(const char* text, int x, int y, int r, int g, int b, int a, TTF_Font* font, std::tuple<int,int,int>origin, Object &parentClass, int spacing = 0);
    std::tuple<int, int, int> initText(const char* text, int x, int y, int r, int g, int b, int a, TTF_Font* font, std::tuple<int,int,int>origin);
    void initObject(Object &o, Object const &parentClass, int spacing = 0);
    void initObject(Object &o);
    void initFileConfig(std::string filename, std::vector<char>heights, int w, int h, int x=0, int y=0);
    void initFile(Tile &o, std::string filename);
    void removeFile(const char* filename);
    void removeFileRect(std::string filename, int widthFile, SDL_Rect &rect);
    void initFileSpace(std::string filename);
};
#endif//DRAW_H