#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
private:
    int left, right, up, down;
    int idolLeft, idolRight, runLeft, runRight, jumpRight;
    SDL_Renderer *ren;
public:
    Player(SDL_Renderer *r);
    void input(SDL_Event &e);
    void update();
};

#endif//PLAYER_H