#ifndef DEBUG_H
#define DEBUG_H

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
#include "../collisions.h"
#include "../entity.h"

class Debug {
private:
    SDL_Renderer* ren;
    vector<SDL_Rect> colliders;
    bool activated;
    int frameCount;
public:
    Debug(SDL_Renderer* &r);
    ~Debug();
    bool isActivated() const {return activated;}
    void activate(bool a) {activated=a;}

    void addColliders(Collisions &c);
    void frameIncrement() {frameCount++;}
    void clearFrameCount() {frameCount=0;}
    
    void showCollidersBox();
    string CollisionNumber() const {return to_string(colliders.size());}
    string frameNumber() const {return to_string(frameCount);}
};
#endif//DEBUG_H