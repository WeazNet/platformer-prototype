#include "debugInterface.h"

DebugInterface::DebugInterface(SDL_Renderer* &r, Debug* &d) {
    ren=r;
    debug = d;
    if(!debug->isActivated()) return;
    setImage("res/debugInterface.png", ren);
    setSrc(0, 0, 25, 25);
    setDest(0, 0, 25, 25);
}

DebugInterface::~DebugInterface() {
}

void DebugInterface::render(Draw* &draw) {
    if(!debug->isActivated()) return;
    tuple<int, int, int> currentOrigin = {0, 0, 0};
    draw->initObject(*this);
    currentOrigin = draw->initText("Debug Interface", 10, 10, 0, 0, 255, 255, font.getBold(), currentOrigin, *this, 20);
    currentOrigin = draw->initText(("Frame number: " + debug->frameNumber()).c_str(), 10, 10, 255, 255, 255, 255, font.getItalic(), currentOrigin, *this, 20);
    currentOrigin = draw->initText(("Collision number: " + debug->CollisionNumber()).c_str(), 10, 10, 255, 255, 255, 255, font.getItalic(), currentOrigin, *this, 20);
}