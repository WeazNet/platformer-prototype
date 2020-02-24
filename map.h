#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include <vector>
#include <SDL2/SDL.h>

#include "object.h"
#include "entity.h"
#include "draw.h"
#include "collisions.h"
#include "debug/debug.h"

#define TILE_SIZE 25

class Map{
private:
    int mapX, mapY;
    SDL_Renderer* ren;
    Debug* debug;
    vector<Object> map;
public:
    Map(SDL_Renderer* &r, Debug* &d);
    ~Map();
    void load(string tileset, const char* filename, int size);
    vector<Object> getMap() {return map;}
    void draw();
};

#endif //MAP_H