#include "map.h"
Map::Map(SDL_Renderer* r) {
    ren=r;
    mapX=mapY=0;
}
Map::~Map(){
}

void Map::load(const char* filename, string tileset) {
    Object tmp;
    tmp.setImage(tileset, ren);
    int current, mx, my, mw, mh;
    fstream in(filename);
    if(!in.is_open()) {
        cout << "Impossible de charger l'image: " << filename << endl;
        return;
    }
    in >> mx;
    in >> my;
    in >> mw;
    in >> mh;

    for(int i=0;i<(int)mh;i++) {
        for(int j=0;j<(int)mw;j++) {
            if(in.eof()) {
                cout << "Chargement de la carte impossible" << endl;
                return;
            }
            in >> current;
            if((int)current != 0) {
                tmp.setSrc((current-1)*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE);
                tmp.setDest((j*TILE_SIZE)+mx, (i*TILE_SIZE)+my, TILE_SIZE, TILE_SIZE);
                tmp.setSolid(1);
                if(current == 4 || current == 3) {tmp.setSolid(0);}
                tmp.setID(current);
                map.push_back(tmp);
            }
        }
    }
    in.close();
}

void Map::draw() {
    Draw tmp(ren);
    for(int i=0; i<(int)map.size();i++){
        tmp.init(map[i]);
    }
}
void Map::updateCollision(Entity *a) {
    a->setFall(1);
    a->setLockJump(1);
    for(int i=0;i<(int)map.size();i++) {
        if(Object::collision(a, map[i])) {
            if(map[i].isSolid()) {
                    a->setFall(0);
                    a->setLockJump(0);
                /* Si collision ≠ sur le dessus du bloc */
                if((a->getDY()+a->getDH()) >= (map[i].getDY()+a->getVGrav())) {
                    a->setFall(1);
                    a->setLockJump(1);
                    /* Si collision sur les côtés du bloc */
                    if(a->getDX() < (map[i].getDX()+map[i].getDW())) {
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
