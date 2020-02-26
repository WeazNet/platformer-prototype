#ifndef DEBUG_H
#define DEBUG_H

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
#include "../collisions.h"
#include "../entity.h"
#include "../draw.h"

class Debug {
protected:
    static vector<SDL_Rect> colliders;
    static bool activated;
    static int frameCount;
public:
    Debug();
    ~Debug();
    static void activate(bool a) {activated=a;}
    static bool isActive() {return activated;}
    static void addColliders(Collisions &c);
    static void frameIncrement() {if(activated) frameCount++;}
    static void clearFrameCount() {frameCount=0;}
};
#endif//DEBUG_H