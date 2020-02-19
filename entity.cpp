#include "entity.h"

int Entity::createCycle(int row, int w, int h, int amount, int speed) {
    cycle tmp;
    tmp.row = row-1;
    tmp.w = w;
    tmp.h = h;
    tmp.amount = amount;
    tmp.speed = speed;
    tmp.tick = 0;
    animations.push_back(tmp);
    return animations.size()-1;
}

void Entity::updateAnimation() {
    setSrc(animations[curAnimation].tick*animations[curAnimation].w,
    animations[curAnimation].row*animations[curAnimation].h,
    animations[curAnimation].w, animations[curAnimation].h);
    if(begin > animations[curAnimation].speed) {
        (!reverse) ? animations[curAnimation].tick++ : animations[curAnimation].tick--;
        begin=0;
    }
    begin++;
    if(animations[curAnimation].tick >= animations[curAnimation].amount) {
        animations[curAnimation].tick=0;
    }
}