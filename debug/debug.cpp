#include "debug.h"

Debug::Debug(SDL_Renderer* &r) {
    ren=r;
}

Debug::~Debug() {
}

void Debug::showCollidersBox(bool active, Utils &u) {
    if(!activated) {return;}
    if(active) {
       objects = u.getListObjectsDest();
       for(int i=0;i<(int)objects.size();i++) {
            SDL_SetRenderDrawColor(ren, 0, 0, 255, 255 );
            SDL_RenderDrawRect(ren, &objects[i]);
       }
    }
}