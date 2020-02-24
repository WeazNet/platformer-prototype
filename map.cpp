#include "map.h"
Map::Map(SDL_Renderer* &r, Debug* &d) {
    debug=d;
    ren=r;
    mapX=mapY=0;
}
Map::~Map(){
}

void Map::loadTileset(const std::string &t) {
    tileset=t;
}

void Map::load(const std::string &componentName, const char* filename, int size, bool isphysical) {
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
                if(isphysical) {
                    tmp.setSolid(1);
                    if(current == 4 || current == 3) {tmp.setSolid(0);}
                } else {
                    tmp.setSolid(0);
                    current=4;
                    /** Temporary => TODO : tileset for no physical **/
                }
                tmp.setID(current);
                tmp.setSrc((current-1)*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE);
                tmp.setDest((j*size)+mx, (i*size)+my, size, size);
                map[componentName].push_back(tmp);
            }
        }
    }
    in.close();
}

void Map::draw(const std::string &componentName) {
    Draw tmp(ren, debug);
    for(int i=0; i<(int)map[componentName].size();i++){
        tmp.initObject(map[componentName][i]);
    }
}
void Map::updateCollision(Entity* a, Utils &u) {
    a->setFall(1);
    a->setLockJump(1);
    for(int i=0;i<(int)map["map"].size();i++) {
        if(Object::collision(a, &map["map"][i])) {
            if(map["map"][i].isSolid()) {
                    u.addObject(map["map"][i]);
                    a->setFall(0);
                    a->setLockJump(0);
                /* Si collision ≠ sur le dessus du bloc */
                if((a->getDY()+a->getDH()) >= (map["map"][i].getDY()+a->getVGrav())) {
                    a->setFall(1);
                    a->setLockJump(1);
                    /* Si collision sur les côtés du bloc */
                    if(a->getDX() < (map["map"][i].getDX()+map["map"][i].getDW())) {
                        /* Si collision sur la droite du bloc */
                        if(a->getCurrentAnimation() == 1 || a->getCurrentAnimation() == 3) {
                            a->setDest(a->getDX()+a->getSpeed(), a->getDY());
                        } 
                        /* Si collision sur la gauche du bloc */
                        else if(a->getCurrentAnimation() == 0 || a->getCurrentAnimation() == 2) {
                            a->setDest(a->getDX()-a->getSpeed(), a->getDY());
                        }
                        /* Si collision en dessous du bloc */
                        else if(a->getCurrentAnimation() == 4 || a->getCurrentAnimation() == 5) {
                            a->setDest(a->getDX(), a->getDY()+a->getSpeed()-a->getVGrav());
                        }
                    }
                }
            }
        }
    }
}