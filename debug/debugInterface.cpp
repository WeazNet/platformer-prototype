#include "debugInterface.h"

DebugInterface::DebugInterface(SDL_Renderer* &r) {
    ren=r;
    draw = new Draw(ren);
    if(!activated)return;
    setImage("res/debugInterface.png", ren);
    setSrc(0, 0, 25, 25);
    setDest(0, 0, 25, 25);
}

DebugInterface::~DebugInterface() {
    deleteAll(draw);
}

void DebugInterface::render() {
    if(!activated)return;
    std::tuple<int, int, int> origin = {0, 0, 0};
    draw->initObject(*this);
    origin=addElement(origin, "Debug Interface", "", font.getBold());
    origin=addElement(origin, "FPS:", std::to_string(Debug::fps));
    origin=addElement(origin, "Frame number charged:", std::to_string(Debug::frameCount));
    origin=addElement(origin, "Collision number:", std::to_string(Debug::colliders.size()));
    origin=addElement(origin, "Mouse pos x:", std::to_string(Debug::mouseX));
    origin=addElement(origin, "Mouse pos y:", std::to_string(Debug::mouseY));
}

tuple<int,int,int> DebugInterface::addElement(std::tuple<int,int,int>origin, std::string label, std::string value, TTF_Font* f) {
    if(f == NULL) f=font.getItalic();
    return draw->initText((label+" "+value).c_str(), 10, 10, 0, 0, 0, 255, f, origin, *this, 20);
}

void DebugInterface::showCollidersBox() {
    if(!activated)return;
    for(int i=0;i<(int)colliders.size();i++) {
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255 );
        SDL_RenderDrawRect(ren, &colliders[i]);
    }
}