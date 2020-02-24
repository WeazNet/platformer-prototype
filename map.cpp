#include "map.h"
Map::Map(SDL_Renderer* &r, Debug* &d) {
    debug=d;
    ren=r;
    mapX=mapY=0;
}
Map::~Map(){
}

void Map::load(string tileset,const char* filename, int size) {
    Object tmp;
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
                if(current == 4 || current == 3) {
                tmp.setSolid(0);
                } else {
                tmp.setSolid(1);
                }
                tmp.setID(current);
                tmp.setSrc((current-1)*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE);
                tmp.setDest((j*size)+mx, (i*size)+my, size, size);
                map.push_back(tmp);
            }
        }
    }
    in.close();
}

void Map::draw() {
    Draw tmp(ren, debug);
    for(int i=0; i<(int)map.size();i++){
        tmp.initObject(map[i]);
    }
}
