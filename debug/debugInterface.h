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
    Font font;
public:
    DebugInterface(SDL_Renderer* &r);
    ~DebugInterface();
    void render();
    std::tuple<int,int,int> addElement(std::tuple<int,int,int>origin, std::string label, std::string value = "", TTF_Font* f = NULL);
    void showCollidersBox();
};
#endif//DEBUG_INTERFACE_H