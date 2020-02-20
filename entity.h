#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "object.h"

class Entity : public Object {
protected:
    bool fall, lockJump, jump;
    int v_y=-48, v_grav=6;
    int health, maxHealth, speed=6;
    int idolRight, idolLeft, runLeft, runRight, jumpRight, jumpLeft;
    struct cycle {
        int row;
        int w;
        int h;
        int amount;
        int speed;
        int tick;
    };
    std::vector<cycle> animations;
    int curAnimation, begin, newAnimation=-1;
    bool reverse;
public:
    void setHealth(int h) {health=h;}
    void setMaxHealth(int h) {maxHealth=h;}
    void setCurrentAnimation(int c) {curAnimation=c;};
    void setCurrentAnimation(int c, int nA) {curAnimation=c;newAnimation=nA;};
    int getHealth() const {return health;}
    int getMaxHealth() const {return maxHealth;}
    int getCurrentAnimation() const {return curAnimation;};
    int getSpeed() const {return speed;}
    bool isFall() const {return fall;}
    bool isReverse() const {return reverse;}
    int createCycle(int row, int w, int h, int amount, int speed);
    void updateAnimation();
    void setFall(bool f) {fall=f;}
    void setLockJump(bool l) {lockJump=l;}
    void evolutionJump(int v_x);
    void updateJump();
    int getVGrav() const {return v_grav;}
};

#endif //ENTITY_H