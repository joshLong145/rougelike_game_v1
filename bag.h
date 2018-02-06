#ifndef bag_h
#define bag_h
// INCLUDE STATEMENTS
#include "baseItem.h"
#include "healthIncreaseItem.h"
#include <vector>
#include <memory>

class Bag{
public:

    /*
        paramater: none,
        return: vector of unique pointers of the baseItem class
        description: returns a refrence to the vector of unique pointers holding
        baseItem objects.
    */
    std::vector<std::shared_ptr<baseItem>> & getItems();

    /*
        paramater: enum items
        return: void
        description: adds an object derived from the baseItem class used to modify
        player atrributes. Stores said objects within a vector of unique pointers.
    */
    void addItem(std::shared_ptr<baseItem> item);

public:

    std::vector<std::shared_ptr<baseItem>> m_itemStorage;
};
#endif
