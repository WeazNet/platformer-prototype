#include "inventory.h"

Inventory::Inventory(SDL_Renderer* &r) {
    ren=r;
    draw = new Draw(ren);

    inventory.push_back(std::unique_ptr<Dirt>(new Dirt));
    /** update items **/
    for(int i=0;i<(int)inventory.size();i++) {
        inventory[i]->setImage(inventory[i]->getSourceFile(), ren);
    }

    setImage("resources/object_menu.png", ren);
    setSrc(0,0,TILE_SIZE,TILE_SIZE);
    setDest(WIDTH/2-ITEM_SIZE*6, 0, (ITEM_SIZE*2)*6, ITEM_SIZE*2);
}

Inventory::~Inventory() {
    deleteAll(draw);
}

void Inventory::render() {
    draw->initObject(*this);
    SDL_Rect origin = {0, 0, ITEM_SIZE, ITEM_SIZE};
    for(int i=0;i<(int)inventory.size();i++) {
        origin = draw->initObject(*inventory[i], *this, "right", origin, ITEM_SIZE/2);
        origin = draw->initText("0", 255, 0, 0, 255, Font::getRegular(), origin, *this, "bottom_right", true, {0,0});
    }
}

void Inventory::update() {
    
}