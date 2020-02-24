#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include <vector>
#include <SDL2/SDL.h>

#include "object.h"
#include "entity.h"
#include "draw.h"
#include "utils.h"
#include "debug/debug.h"

#define TILE_SIZE 25

class Map{
private:
    int mapX, mapY;
    std::string tileset;
    SDL_Renderer* ren;
    Debug* debug;
    std::map<std::string, std::vector<Object>> map;
public:
    Map(SDL_Renderer* &r, Debug* &d);
    ~Map();
    void loadTileset(const std::string &t);
    void load(const std::string &componentName, const char* filename, int size, bool isphysical);
    void draw(const std::string &componentName);
    void updateCollision(Entity *a, Utils &u);
};

#endif //MAP_H