#include "utils.h"
std::vector<SDL_Rect> Utils::getListObjectsDest() {
    std::vector<SDL_Rect> objectsDest;
    for(int i=0; i<(int)listObjects.size(); i++) {
        SDL_Rect rect;
        rect.x=listObjects[i].getDX();
        rect.y=listObjects[i].getDY();
        rect.w=listObjects[i].getDW();
        rect.h=listObjects[i].getDH();
        objectsDest.push_back(rect);
    }
    return objectsDest;
}
void Utils::addObject(Object &o) {
    listObjects.push_back(o);
}
void Utils::clearObjects() {
    listObjects.clear();
}