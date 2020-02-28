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

enum Level {
    UNBREAKABLE,
    HAND,
    PICKAXE
};

enum Markable {
    INVISIBLE,
    VISIBLE
};

class Tile : public Object{
protected:
    int id, location, type, harvestLevel;
    float durability;
    bool marking;
public:
    Tile();
    ~Tile();
    void init(int t);
    int getId() const {return id;}
    void setId(int i) {id=i;}
    int getLocation() const {return location;}
    void setLocation(int l) {location=l;}
    int getType() const {return type;}
    void setType(int t) {type=t;}
    int getDurability() const {return durability;}
    void setDurability(float d) {durability=d;}
    void decreaseDurability(float v) {durability-=v;}
    void setHarvestLevel(int h) {harvestLevel=h;}
    int getHarvestLevel() const {return harvestLevel;}
    void setMarking(bool m) {marking=m;}
    bool onMarking() const {return marking;}
};

#endif//TILE_H