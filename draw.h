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
    SDL_Rect initText(const char* text, int r, int g, int b, int a, TTF_Font* font, SDL_Rect origin, Object &parentClass, std::string orientation, bool first, std::tuple<int,int> spacing = {0,0});
    SDL_Rect initObject(Object &o, Object &parentClass, std::string orientation, SDL_Rect origin, int spacing = 0);
    void initObject(Object &o);
    void initFileConfig(std::string filename, std::vector<char>heights, int w, int h, int x=0, int y=0);
    void initFile(Tile &o, std::string filename);
    void removeFile(const char* filename);
    void removeFileRect(std::string filename, int widthFile, SDL_Rect &rect);
    void initFileSpace(std::string filename);
};
#endif//DRAW_H