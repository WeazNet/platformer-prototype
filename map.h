#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include <vector>
#include <SDL2/SDL.h>

#include "object.h"
#include "entity.h"
#include "draw.h"

#define TILE_SIZE 25

class Map{
private:
    int mapX, mapY;
    std::string tileset;
    SDL_Renderer* ren;
    std::map<std::string, std::vector<Object>> map;
public:
    Map(SDL_Renderer* &r);
    ~Map();
    void loadTileset(const std::string &t);
    void load(const std::string &componentName, const char* filename, int size, bool isphysical);
    void draw(const std::string &componentName);
    void updateCollision(Entity *a);
};

#endif //MAP_H