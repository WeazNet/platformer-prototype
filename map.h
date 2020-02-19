#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <vector>
#include <SDL2/SDL.h>

#include "object.h"
#include "entity.h"
#include "draw.h"

#define TILE_SIZE 25

class Map{
private:
    int mapX, mapY;
    SDL_Renderer* ren;
    vector<Object> map;
public:
    Map(SDL_Renderer* r);
    ~Map();
    void load(const char* filename, string tileset);
    void draw();
    void updateCollision(Entity *a);
    vector<Object> getMap() const {return map;}
};

#endif //MAP_H