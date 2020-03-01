#include "debugInterface.h"

DebugInterface::DebugInterface(SDL_Renderer* &r) {
    ren=r;
    draw = new Draw(ren);
    if(!activated)return;
    setImage("resources/object_menu.png", ren);
    setSrc(0, 0, 25, 25);
    setDest(950, 25, 25, 25);
}

DebugInterface::~DebugInterface() {
    deleteAll(draw);
}

void DebugInterface::render() {
    if(!activated)return;
    SDL_Rect origin;
    origin.x=getDX();
    origin.y=getDY();

    draw->initObject(*this);
    origin=addElement(origin, "Debug Interface", "", "bottom", true, Font::getBold());
    origin=addElement(origin, "FPS:", std::to_string(Debug::fps));
    origin=addElement(origin, "Frame number charged:", std::to_string(Debug::frameCount));
    origin=addElement(origin, "Collision number:", std::to_string(Debug::colliders.size()));
    origin=addElement(origin, "Mouse pos x:", std::to_string(Debug::mouseX));
    origin=addElement(origin, "Mouse pos y:", std::to_string(Debug::mouseY));
}

SDL_Rect DebugInterface::addElement(SDL_Rect origin, std::string label, std::string value, std::string orientation, bool first, TTF_Font* f) {
    if(f == NULL) f=Font::getItalic();
    return draw->initText((label+" "+value).c_str(), 0, 0, 0, 255, f, origin, *this, orientation, first, {20, 10});
}

void DebugInterface::showCollidersBox() {
    if(!activated)return;
    for(int i=0;i<(int)colliders.size();i++) {
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255 );
        SDL_RenderDrawRect(ren, &colliders[i]);
    }
}