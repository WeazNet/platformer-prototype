#include "debug.h"

int Debug::frameCount = 0;
std::vector<SDL_Rect> Debug::colliders = {};
bool Debug::activated = false;
int Debug::mouseX = 0;
int Debug::mouseY = 0;
int Debug::fps = 0;

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