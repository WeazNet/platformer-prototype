#include "object.h"

Object::Object() {
}

Object::~Object() {
    
}

void Object::setSrc(int x, int y, int w, int h) {
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
}

void Object::setDest(int x, int y, int w, int h) {
    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;
}

void Object::setDest(int x, int y) {
    dest.x=x;
    dest.y=y;
}

void Object::setImage(const std::string filename, SDL_Renderer* &ren) {
    tex = IMG_LoadTexture(ren, filename.c_str());
}
