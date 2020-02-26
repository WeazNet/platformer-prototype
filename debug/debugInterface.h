#ifndef DEBUG_INTERFACE_H
#define DEBUG_INTERFACE_H
#include <tuple>
#include <iostream>
using namespace std;
#include "../object.h"
#include "../draw.h"
#include "../font.h"
#include "debug.h"
class DebugInterface : public Object, public Debug {
private:
    SDL_Renderer *ren;
    Font font;
public:
    DebugInterface(SDL_Renderer* &r);
    ~DebugInterface();
    void render(Draw* &draw);
    void showCollidersBox();
};
#endif//DEBUG_INTERFACE_H