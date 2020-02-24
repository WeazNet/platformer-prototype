#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <SDL2/SDL.h>

#include "object.h"

class Utils {
protected:
    std::vector<Object> listObjects;
public:
    void addObject(Object &o);
    void clearObjects();
    std::vector<SDL_Rect>getListObjectsDest();
};
#endif//UTILS_H
