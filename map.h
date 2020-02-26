#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include <vector>
#include <SDL2/SDL.h>

#include "tile.h"
#include "player.h"
#include "draw.h"

#include "define.h"

class Map{
private:
    SDL_Renderer* ren;
    vector<Object> map;
public:
    Map(SDL_Renderer* &r);
    ~Map();
    void load(string tileset, const char* filename, int size);
    vector<Object> getMap() {return map;}
    void draw();
    void scroll(int x, int y);
};

#endif //MAP_H