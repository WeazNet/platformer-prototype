#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
using namespace std;
#include <SDL2/SDL_image.h>

class Object {
private:
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* tex;
    bool solid;
    int ID;
public:
    Object();
    ~Object();
    void setSrc(int x, int y, int w, int h);
    void setDest(int x, int y, int w, int h);
    void setDest(int x, int y);
    void setImage(string filename, SDL_Renderer* ren);
    SDL_Rect getSrc() const {return src;}
    SDL_Rect getDest() const {return dest;}
    SDL_Texture* getTex() const {return tex;}
    int getDX() const {return dest.x;}
    int getDY() const {return dest.y;}
    int getDW() const {return dest.w;}
    int getDH() const {return dest.h;}
    bool isSolid() const {return solid;}
    void setSolid(bool s) {solid=s;}
    int getID() const {return ID;}
    void setID(int i) {ID=i;}
    static bool collision(Object *a, Object b);
};

#endif //OBJECT_H