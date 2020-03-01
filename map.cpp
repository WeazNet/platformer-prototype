#include "map.h"

std::vector<Tile> Map::map = {};
std::string Map::name = "";
int Map::width = 0;

Map::Map(SDL_Renderer* &r) {
    ren=r;
}
Map::~Map(){
}

void Map::load(std::string tileset, const char* filename) {
    name=filename;
    Tile tmp;
    tmp.setImage(tileset, ren);
    int id, location, current, mx, my, mw, mh;
    id=0;location=1;
    std::fstream in(filename);
    if(!in.is_open()) {
        std::cout << "Impossible de charger l'image: " << filename << std::endl;
        return;
    }
    in >> mx;
    in >> my;
    in >> mw;
    in >> mh;
    width=mw;
    for(int i=0;i<(int)mh;i++) {
        for(int j=0;j<(int)mw;j++) {
            if(in.eof()) {
                std::cout << "Chargement de la carte impossible" << std::endl;
                return;
            }
            in >> current;
            if((int)current != 0) {
                tmp.setId(id);
                tmp.setLocation(location);
                id++;location++;
                tmp.setSrc((current-1)*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE);
                tmp.setDest((j*TILE_SIZE)+mx, (i*TILE_SIZE)+my, TILE_SIZE, TILE_SIZE);
                tmp.init(current);
                map.push_back(tmp);
            } else {
                location++;
            }
        }
    }
    in.close();
}

void Map::draw() {
    Draw tmp(ren);
    for(int i=0; i<(int)map.size();i++){
        if(map[i].getDX() < WIDTH+TILE_SIZE && map[i].getDX() > 0-TILE_SIZE && map[i].getDY() < HEIGHT+TILE_SIZE && map[i].getDY() > 0-TILE_SIZE) {
            if(map[i].onMarking()) tmp.initObject(map[i]);
        }
    }
}

void Map::scroll(int x, int y) {
    for(int i=0; i<(int)map.size(); i++) {
        map[i].setDest(map[i].getDX()+x, map[i].getDY()+y);
    }
}

void Map::hydrate(Tile &t) {
    map[t.getId()] = t;
}

std::vector<Tile> Map::getMapNearby(SDL_Rect player) {
    std::vector<Tile> tilesNearby;
    for(int i=0;i<(int)map.size();i++) {
        if(map[i].getDY() > player.y-2*TILE_SIZE && map[i].getDY() < player.y+player.h+2*TILE_SIZE && map[i].getDX() > player.x-2*TILE_SIZE && map[i].getDX() < player.x+player.w+2*TILE_SIZE) {
            tilesNearby.push_back(map[i]);
        }
    }
    return tilesNearby;
}