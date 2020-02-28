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
    std::string GenerationTmp(std::string filename);
    void Generation(std::string filename);
};
#endif//GENERATE_H