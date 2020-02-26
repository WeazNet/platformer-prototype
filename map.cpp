#include "map.h"
Map::Map(SDL_Renderer* &r) {
    ren=r;
}
Map::~Map(){
}

void Map::load(string tileset,const char* filename, int size) {
    Tile tmp;
    tmp.setImage(tileset, ren);
    int current, mx, my, mw, mh;
    std::fstream in(filename);
    if(!in.is_open()) {
        std::cout << "Impossible de charger l'image: " << filename << std::endl;
        return;
    }
    in >> mx;
    in >> my;
    in >> mw;
    in >> mh;

    for(int i=0;i<(int)mh;i++) {
        for(int j=0;j<(int)mw;j++) {
            if(in.eof()) {
                std::cout << "Chargement de la carte impossible" << std::endl;
                return;
            }
            in >> current;
            if((int)current != 0) {
                tmp.setType(current);
                tmp.setSrc((current-1)*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE);
                tmp.setDest((j*size)+mx, (i*size)+my, size, size);
                map.push_back(tmp);
            }
        }
    }
    in.close();
}

void Map::draw() {
    Draw tmp(ren);
    for(int i=0; i<(int)map.size();i++){
        if(map[i].getDX() < WIDTH+TILE_SIZE && map[i].getDX() > 0-TILE_SIZE && map[i].getDY() < HEIGHT+TILE_SIZE && map[i].getDY() > 0-TILE_SIZE) {
            tmp.initObject(map[i]);
        }
    }
}

void Map::scroll(int x, int y) {
    for(int i=0; i<(int)map.size(); i++) {
        map[i].setDest(map[i].getDX()+x, map[i].getDY()+y);
    }
}