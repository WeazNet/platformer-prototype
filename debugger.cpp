#include "debugger.h"

Debugger::Debugger(SDL_Renderer* &r) {
    ren=r;
}

Debugger::~Debugger() {
}

void Debugger::viewCollidersBox(bool active, Utils &u) {
    if(!activated) {return;}
    if(active) {
       std::vector<SDL_Rect> entities = u.getListEntitiesDest();
       for(int i=0;i<(int)entities.size();i++) {
            SDL_SetRenderDrawColor(ren, 255, 0, 0, 255 );
            SDL_RenderDrawRect(ren, &entities[i]);
       }
    }
}

