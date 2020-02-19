#include "player.h"

Player::Player(SDL_Renderer *r) {
    ren=r;
    left=right=up=0;
    setImage("res/player.png", ren);
    setDest(0, 0, 14*4, 21*4);
    idolLeft = createCycle(2, 14, 21, 2, 20);
    idolRight = createCycle(1, 14, 21, 2, 20);
    runRight = createCycle(3, 14, 21, 4, 5);
    runLeft = createCycle(4, 14, 21, 4, 5);
    jumpRight = createCycle(5, 14, 21, 4, 5);
    
    setCurrentAnimation(idolRight);
}

void Player::input(SDL_Event &e) {
    if(e.type == SDL_KEYDOWN) {
        if(e.key.keysym.sym == SDLK_d) {right=1;left=0;}
        if(e.key.keysym.sym == SDLK_q) {left=1;right=0;}
        if(e.key.keysym.sym == SDLK_z) {up=1;down=0;}
    }
    if(e.type == SDL_KEYUP) {
        if(e.key.keysym.sym == SDLK_d) {
            right=0;
            setCurrentAnimation(idolRight);
        }
        if(e.key.keysym.sym == SDLK_q) {
            left=0;
            setCurrentAnimation(idolLeft);
        }
        if(e.key.keysym.sym == SDLK_z) {
            up=0;
        }
    }
}

void Player::update() {
    if(left) {if(getCurrentAnimation() != runRight){setCurrentAnimation(runLeft);} setDest(getDX()-SPEED, getDY());}
    if(right) {if(getCurrentAnimation() != runLeft){setCurrentAnimation(runRight);} setDest(getDX()+SPEED, getDY());}
    if(up && !lockJump) {setCurrentAnimation(jumpRight); /** TODO: Système de saut **/}
}