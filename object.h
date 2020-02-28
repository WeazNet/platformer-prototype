#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
#include <SDL2/SDL_image.h>
#include "define.h"

enum Solid {
    AIR,
    BLOCK
};

class Object {
protected:
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* tex;
    bool solid;
public:
    Object();
    ~Object();
    void setSrc(int x, int y, int w, int h);
    void setDest(int x, int y, int w, int h);
    void setDest(int x, int y);
    void setImage(const std::string filename, SDL_Renderer* &ren);
    SDL_Rect getSrc() const {return src;}
    SDL_Rect getDest() const {return dest;}
    SDL_Texture* getTex() const {return tex;}
    int getDX() const {return dest.x;}
    int getDY() const {return dest.y;}
    int getDW() const {return dest.w;}
    int getDH() const {return dest.h;}
    bool isSolid() const {return solid;}
    void setSolid(bool s) {solid=s;}
};

#endif //OBJECT_H