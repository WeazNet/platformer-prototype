#include "player.h"

Player::Player(SDL_Renderer* &r) {
    ren=r;
    left=right=up=0;
    setImage("res/player.png", ren);
    setDest(0, 0, 14*4, 21*4);
    setSolid(1);
    createCycle(IDOL_RIGHT, 14, 21, 2, 20);
    createCycle(IDOL_LEFT, 14, 21, 2, 20);
    createCycle(RUN_RIGHT, 14, 21, 4, 5);
    createCycle(RUN_LEFT, 14, 21, 4, 5);
    createCycle(JUMP_RIGHT, 14, 21, 4, 10);
    createCycle(JUMP_LEFT, 14, 21, 4, 10);
    setCurrentAnimation(IDOL_RIGHT);
}

Player::~Player() {
    
}

void Player::input(SDL_Event &e) {
    if(e.type == SDL_KEYDOWN) {
        if(e.key.keysym.sym == SDLK_d) {right=1;}
        if(e.key.keysym.sym == SDLK_q) {left=1;}
        if(e.key.keysym.sym == SDLK_z) {up=1;}
    }
    if(e.type == SDL_KEYUP) {
        if(e.key.keysym.sym == SDLK_d) {
            right=0;
            setCurrentAnimation(IDOL_RIGHT);
        }
        if(e.key.keysym.sym == SDLK_q) {
            left=0;
            setCurrentAnimation(IDOL_LEFT);
        }
        if(e.key.keysym.sym == SDLK_z) {
            up=0;
        }
    }
}

void Player::updateMouse(vector<Object> map) {
    SDL_GetMouseState(&mouseX, &mouseY);
    Debug::hydratePosMouse(mouseX, mouseY);
    for(int i=0; i<(int)map.size();i++) {
        /**TODO:Calcul mouse & tile position**/
    }
}

void Player::update() {
    if(left) {if(getCurrentAnimation() != RUN_RIGHT){setCurrentAnimation(RUN_LEFT);} setDest(getDX()-speed, getDY());}
    if(right) {if(getCurrentAnimation() != RUN_LEFT){setCurrentAnimation(RUN_RIGHT);} setDest(getDX()+speed, getDY());}
    if(up && !lockJump) {jump=true;}
    updateJump();
}