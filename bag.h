#ifndef bag_h
#define bag_h

#include "baseItem.h"
#include <vector>
#include <memory>

class Bag{
public:
    void getItems();
    void addItem(baseItem item);
public:
    std::vector<std::unique_ptr> itemStorage;
};
