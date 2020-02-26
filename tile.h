#ifndef TILE_H
#define TILE_H

#include "object.h"

#define TILE_SIZE 32

enum Type {
    NONE,
    STONE,
    DIRT,
    GRASS
};

class Tile : public Object{
protected:
    int type;
public:
    Tile();
    ~Tile();
    int getType() const {return type;}
    void setType(int t) {type=t;}
};

#endif//TILE_H