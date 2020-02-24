#include "debugInterface.h"

DebugInterface::DebugInterface(SDL_Renderer* &r, Debug* &d) {
    ren=r;
    debug = d;
    if(!debug->isActivated()) return;
    setImage("res/debugInterface.png", ren);
    setSrc(0, 0, 25, 25);
    setDest(0, 0, 250, 100);     
}

DebugInterface::~DebugInterface() {
}

void DebugInterface::render(Draw* &draw) {
    if(!debug->isActivated()) return;
    tuple<int, int> currentOrigin = {0, 0};
    draw->init(*this);
    currentOrigin = draw->init("Debug Interface", 10, 10, 0, 0, 255, 255, font.getBold(), currentOrigin);
    currentOrigin = draw->init(("Frame number: " + debug->frameNumber()).c_str(), 10, 10, 255, 255, 255, 255, font.getItalic(), currentOrigin);
    currentOrigin = draw->init(("Collision number: " + debug->CollisionNumber()).c_str(), 10, 10, 255, 255, 255, 255, font.getItalic(), currentOrigin);
}