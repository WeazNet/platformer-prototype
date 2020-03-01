#include "item.h"

Item::Item() {
    name="undefined";
    itemState=IS_NOT_ACTIVE;
    sourceFile="resources/item_list.png";
}
Item::~Item() {

}
Dirt::Dirt() {
    name="Dirt";
    setSrc(0,0,ITEM_SIZE,ITEM_SIZE);
}
Dirt::~Dirt() {

}