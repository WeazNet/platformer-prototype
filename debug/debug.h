#ifndef DEBUG_H
#define DEBUG_H

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

#include "../utils.h"
#include "../entity.h"

class Debug {
private:
    SDL_Renderer* ren;
    vector<SDL_Rect> objects;
    bool activated;
    int frameCount;
public:
    Debug(SDL_Renderer* &r);
    ~Debug();
    bool isActivated() const {return activated;}
    void activate(bool a) {activated=a;}
    void showCollidersBox(bool active, Utils &u);
    void frameIncrement() {frameCount++;}
    void clearFrameCount() {frameCount=0;}
    string CollisionNumber() const {return to_string(objects.size());}
    string frameNumber() const {return to_string(frameCount);}
};
#endif//DEBUG_H