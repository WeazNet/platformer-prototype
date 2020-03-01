#ifndef DEBUG_INTERFACE_H
#define DEBUG_INTERFACE_H
#include <tuple>
#include <iostream>
using namespace std;
#include "../object.h"
#include "../draw.h"
#include "../font.h"
#include "debug.h"

#include "../define.h"

class DebugInterface : public Object, public Debug {
private:
    SDL_Renderer *ren;
    Draw *draw;
public:
    DebugInterface(SDL_Renderer* &r);
    ~DebugInterface();
    void render();
    SDL_Rect addElement(SDL_Rect origin, std::string label, std::string value = "", std::string orientation = "bottom", bool first = false, TTF_Font* f = NULL);
    void showCollidersBox();
};
#endif//DEBUG_INTERFACE_H