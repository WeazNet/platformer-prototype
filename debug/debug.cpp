#include "debug.h"

Debug::Debug(SDL_Renderer* &r) {
    ren=r;
}

Debug::~Debug() {
}

void Debug::addColliders(Collisions &c) {
    colliders.clear();
    for(int i=0;i<(int)c.getColliders().size();i++) {
        colliders.push_back(c.getColliders()[i].getDest());
    }
}

void Debug::showCollidersBox() {
    if(!activated) {return;}
    for(int i=0;i<(int)colliders.size();i++) {
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255 );
        SDL_RenderDrawRect(ren, &colliders[i]);
    }
}