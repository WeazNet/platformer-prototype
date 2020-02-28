#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <vector>
#include <SDL2/SDL.h>

#include "tile.h"
#include "draw.h"

#include "define.h"

class Map{
private:
    SDL_Renderer* ren;
    static std::vector<Tile> map;
    static std::string name;
    static int width;
public:
    Map(SDL_Renderer* &r);
    ~Map();
    void load(std::string tileset, const char* filename);
    static std::vector<Tile> getMap() {return map;}
    static void hydrate(Tile &t);
    static std::vector<Tile> getMapNearby(SDL_Rect player);
    static std::string getName() {return name;}
    static int getWidth() {return width;}
    void draw();
    void scroll(int x, int y);
};

#endif //MAP_H