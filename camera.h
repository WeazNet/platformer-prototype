#ifndef CAMERA_H
#define CAMERA_H

#include "player.h"
#include "map.h"
#include "define.h"

class Camera {
private:
    SDL_Renderer* ren;
    int posX, posY;
public:
    Camera(SDL_Renderer* &r);
    ~Camera();
    void updatePlayerPositionInMap(Map* &map, Player* &player);
};
#endif//CAMERA_H