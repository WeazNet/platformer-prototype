#include "debug.h"

int Debug::frameCount = 0;
vector<SDL_Rect> Debug::colliders = {};
bool Debug::activated = false;

Debug::Debug() {
}

Debug::~Debug() {
}

void Debug::addColliders(Collisions &c) {
    if(!activated)return;
    colliders.clear();
    for(int i=0;i<(int)c.getColliders().size();i++) {
        colliders.push_back(c.getColliders()[i].getDest());
    }
}