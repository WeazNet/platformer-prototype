#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <SDL2/SDL.h>

#include "entity.h"

class Utils {
protected:
    std::vector<Entity> listEntities;
public:
    void addEntity(Entity &e);
    void clearEntities();
    std::vector<SDL_Rect>getListEntitiesDest();
};
#endif//UTILS_H
