#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "entity.h"
#include "tile.h"

class Collisions {
private:
    std::vector<Object> colliders;
public:
    void addCollider(Object &o) {colliders.push_back(o);};
    std::vector<Object> getColliders() const {return colliders;}
    void clearColliders() {colliders.clear();}
    bool isCollision(Object &a, Object &b);
    bool collision(Object &a, Object &b);
    void update(Entity &a, std::vector<Tile> b);
};

#endif//COLLISIONS_H