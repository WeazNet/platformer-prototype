#include "tile.h"
Tile::Tile() {
}
Tile::~Tile() {
}

void Tile::init(int t) {
    type=t;
    setMarking(VISIBLE);
    switch(t) {
        case NONE:
            setMarking(INVISIBLE);
            setHarvestLevel(UNBREAKABLE);
            setDurability(1.0);
            setSolid(AIR);
            break;
        case STONE:
            setHarvestLevel(PICKAXE);
            setDurability(160.0);
            setSolid(BLOCK);
            break;
        case GRASS:
            setHarvestLevel(HAND);
            setDurability(80.0);
            setSolid(BLOCK);
            break;
        case DIRT:
            setHarvestLevel(HAND);
            setDurability(80.0);
            setSolid(BLOCK);
            break;
        default:
        break;
    }
}