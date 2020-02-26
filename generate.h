#ifndef GENERATE_H
#define GENERATE_H

#include <cstdlib>
#include <iterator>
#include <algorithm>
#include "tile.h"
#include "draw.h"
#include "map.h"

#include "define.h"

class Generate {
private:
    SDL_Renderer* ren;
    Draw* draw;
    int width;
    int height;
    int heightAirAdded;
    int distance;
    int space;
    Tile Air;
    Tile Stone;
    Tile Dirt;
    Tile Grass;
public:
    Generate(SDL_Renderer* &r);
    ~Generate();
    string GenerationTmp(string filename);
    void Generation(string filename);
};
#endif//GENERATE_H