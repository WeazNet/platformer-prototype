#include "camera.h"
Camera::Camera(SDL_Renderer* &r) {
    ren=r;
    posX=posY=0;
}
Camera::~Camera() {
}

void Camera::updatePlayerPositionInMap(Map* &map, Player* &player) {
    if(player->getDX() < WIDTH/2) {player->setDest(WIDTH/2, player->getDY()); map->scroll(player->getSpeed(), 0); posX+=player->getSpeed();}
    if(player->getDX() > WIDTH/2) {player->setDest(WIDTH/2, player->getDY()); map->scroll(-player->getSpeed(), 0); posX-=player->getSpeed();}
    if(player->getDY() < 200) {player->setDest(player->getDX(), 200); map->scroll(0, player->getSpeed()); posY+=player->getSpeed();}
    if(player->getDY() > HEIGHT-200) {player->setDest(player->getDX(), HEIGHT-200); map->scroll(0, -player->getSpeed()); posY-=player->getSpeed();}
}