#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "object.h"

#define GRAVITY 6
#define SPEED 5

class Entity : public Object {
protected:
    int health, maxHealth;
    bool fall, lockJump;
    struct cycle {
        int row;
        int w;
        int h;
        int amount;
        int speed;
        int tick;
    };
    vector<cycle> animations;
    int curAnimation, begin;
    bool reverse;
public:
    void setHealth(int h) {health=h;}
    void setMaxHealth(int h) {maxHealth=h;}
    void setCurrentAnimation(int c) {curAnimation=c;};
    void setReverse(bool r) {reverse=r;}
    int getHealth() const {return health;}
    int getMaxHealth() const {return maxHealth;}
    int getCurrentAnimation() const {return curAnimation;};
    bool isFall() const {return fall;}
    bool isReverse() const {return reverse;}
    int createCycle(int row, int w, int h, int amount, int speed);
    void updateAnimation();
    void setFall(bool f) {fall=f;}
    void setLockJump(bool l) {lockJump=l;}
};

#endif //ENTITY_H