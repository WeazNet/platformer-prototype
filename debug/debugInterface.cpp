#include "debugInterface.h"

DebugInterface::DebugInterface(SDL_Renderer* &r) {
    if(!activated)return;
    ren=r;
    setImage("res/debugInterface.png", ren);
    setSrc(0, 0, 25, 25);
    setDest(0, 0, 25, 25);
}

DebugInterface::~DebugInterface() {
}

void DebugInterface::render(Draw* &draw) {
    if(!activated)return;
    tuple<int, int, int> currentOrigin = {0, 0, 0};
    draw->initObject(*this);
    currentOrigin = draw->initText("Debug Interface", 10, 10, 0, 0, 255, 255, font.getBold(), currentOrigin, *this, 20);
    currentOrigin = draw->initText(("Frame number charged: " + to_string(Debug::frameCount)).c_str(), 10, 10, 255, 255, 255, 255, font.getItalic(), currentOrigin, *this, 20);
    currentOrigin = draw->initText(("Collision number: " + to_string(Debug::colliders.size())).c_str(), 10, 10, 255, 255, 255, 255, font.getItalic(), currentOrigin, *this, 20);
}

void DebugInterface::showCollidersBox() {
    if(!activated)return;
    for(int i=0;i<(int)colliders.size();i++) {
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255 );
        SDL_RenderDrawRect(ren, &colliders[i]);
    }
}