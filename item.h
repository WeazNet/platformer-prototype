#ifndef ITEM_H
#define ITEM_H

#define ITEM_SIZE 16

#include "object.h"

enum State {
    IS_NOT_ACTIVE,
    IS_ACTIVE,
    IS_CONSUMED,
    IS_USE
};

class Item : public Object{
protected:
    std::string sourceFile;
    std::string name;
    int itemState;
public:
    Item();
    ~Item();
    std::string getName() const {return name;}
    std::string getSourceFile() const {return sourceFile;}
};

class Dirt : public Item {public:Dirt();~Dirt();};
#endif//ITEM_H

