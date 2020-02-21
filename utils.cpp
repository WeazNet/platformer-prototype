#include "utils.h"
std::vector<SDL_Rect> Utils::getListEntitiesDest() {
    std::vector<SDL_Rect> entitiesDest;
    for(int i=0; i<(int)listEntities.size(); i++) {
        SDL_Rect rect;
        rect.x=listEntities[i].getDX();
        rect.y=listEntities[i].getDY();
        rect.w=listEntities[i].getDW();
        rect.h=listEntities[i].getDH();
        entitiesDest.push_back(rect);
    }
    return entitiesDest;
}
void Utils::addEntity(Entity &e) {
    listEntities.push_back(e);
}
void Utils::clearEntities() {
    listEntities.clear();
}