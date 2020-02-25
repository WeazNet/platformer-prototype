#ifndef COLLISIONS_H
#define COLLISIONS_H

using namespace std;
#include "entity.h"

class Collisions {
private:
    vector<Object> colliders;
public:
    void addCollider(Object &o) {colliders.push_back(o);};
    vector<Object> getColliders() const {return colliders;}
    void clearColliders() {colliders.clear();}
    bool isCollision(Object &a, Object &b);
    bool collision(Object &a, Object &b);
    void update(Entity &a, vector<Object> b);
};

#endif//COLLISIONS_H