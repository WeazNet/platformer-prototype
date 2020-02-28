#include "collisions.h"

bool Collisions::isCollision(Object &a, Object &b) {
    if(a.getDX() < (b.getDX()+b.getDW()) && (a.getDX()+a.getDW()) > b.getDX()
    && a.getDY() < (b.getDY()+b.getDH()) && (a.getDY()+a.getDH()) > b.getDY()) {
        return true;
    }
    return false;
}

bool Collisions::collision(Object &a, Object &b) {
    if(isCollision(a, b)) {
        if(a.isSolid() && b.isSolid()) {
            return true;
        }
        return false;
    }
    return false;
}

void Collisions::update(Entity &a, std::vector<Tile> b) {
    a.setFall(1);
    a.setLockJump(1);
    for(int i=0;i<(int)b.size();i++) {
        if(collision(a, b[i]) && b[i].getType() != NONE) {
            addCollider(b[i]);
            a.setFall(0);
            a.setLockJump(0);
            /* Si collision ≠ sur le dessus du bloc */
            if((a.getDY()+a.getDH()-a.getSpeed()-1) >= (b[i].getDY()+a.getVGrav())) {
                a.setFall(1);
                a.setLockJump(1);
                /* Si collision sur le dessous du bloc */
                if(a.getCurrentAnimation() == JUMP_RIGHT || a.getCurrentAnimation() == JUMP_LEFT) {
                    a.setDest(a.getDX(), a.getDY()+a.getSpeed()*2-a.getVGrav());
                }
                /* Si collision sur les côtés du bloc */
                if(a.getDX()+a.getSpeed() < (b[i].getDX()+b[i].getDW())) {
                /* Si collision sur la droite du bloc */
                    if(a.getCurrentAnimation() == IDOL_LEFT || a.getCurrentAnimation() == RUN_LEFT) {
                        a.setDest(a.getDX()+a.getSpeed(), a.getDY());
                    } 
                    /* Si collision sur la gauche du bloc */
                    else if(a.getCurrentAnimation() == IDOL_RIGHT || a.getCurrentAnimation() == RUN_RIGHT) {
                        a.setDest(a.getDX()-a.getSpeed(), a.getDY());
                    }
                }
            }
        }
    }
}
