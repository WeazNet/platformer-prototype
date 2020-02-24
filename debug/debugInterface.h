#ifndef DEBUG_INTERFACE_H
#define DEBUG_INTERFACE_H
#include <tuple>
#include <iostream>
using namespace std;
#include "../object.h"
#include "../draw.h"
#include "../font.h"
#include "debug.h"
class DebugInterface : public Object {
private:
    Debug *debug;
    SDL_Renderer *ren;
    Font font;
    int FPS;
    float time;
public:
    DebugInterface(SDL_Renderer* &r, Debug* &d);
    ~DebugInterface();
    void render(Draw* &draw);
};
#endif//DEBUG_INTERFACE_H