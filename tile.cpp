#include "tile.h"
Tile::Tile() {
    switch(type) {
        case STONE:
            setSolid(BLOCK);
        break;
        case DIRT:
            setSolid(BLOCK);
        break;
        case GRASS:
            setSolid(BLOCK);
        break;
    }
}
Tile::~Tile() {

}