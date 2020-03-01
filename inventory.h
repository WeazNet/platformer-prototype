#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>

#include "item.h"
#include "draw.h"
#include "font.h"
#include "define.h"

class Inventory : public Object {
private:
    SDL_Renderer* ren;
    Draw* draw;
    int slots;
    std::vector<std::unique_ptr<Item>> inventory;
public:
    Inventory(SDL_Renderer* &r);
    ~Inventory();
    void render();
    void update();

    void addItem() {};
    void removeItem() {};
};

#endif//INVENTORY_H