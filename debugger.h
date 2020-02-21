#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <SDL2/SDL.h>
#include <iostream>

#include "utils.h"

class Debugger {
private:
    SDL_Renderer* ren;
    bool activated;
public:
    Debugger(SDL_Renderer* &r);
    ~Debugger();
    void activate(bool a) {activated=a;}
    void viewCollidersBox(bool active, Utils &u);
};
#endif//DEBUGCMD_H