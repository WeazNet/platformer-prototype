#ifndef DEBUG_H
#define DEBUG_H

#include <SDL2/SDL.h>
#include <iostream>
#include "../collisions.h"

class Debug {
protected:
    static std::vector<SDL_Rect> colliders;
    static bool activated;
    static int frameCount;
    static int mouseX;
    static int mouseY;
    static int fps;
public:
    Debug();
    ~Debug();
    static void activate(bool a) {activated=a;}
    static bool isActive() {return activated;}
    static void addColliders(Collisions &c);
    static void frameIncrement() {if(activated) frameCount++;}
    static void clearFrameCount() {frameCount=0;}
    static void hydratePosMouse(int x, int y) {mouseX=x;mouseY=y;}
    static void hydrateFPS(int f) {fps=f;}
};
#endif//DEBUG_H