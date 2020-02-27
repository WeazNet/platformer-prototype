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

void Object::onAction(SDL_Renderer* &ren, int a) {
    SDL_Rect tmp;
    tmp.h = getDH(); tmp.w = getDW();
    tmp.x = getDX(); tmp.y = getDY();
    switch(a) {
        case HOVERED:
            SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
            SDL_RenderDrawRect(ren, &tmp);
            break;
        case CLICKED:
            break;
        case PRESSED:
            break;
        default:
            break;
    }
}
