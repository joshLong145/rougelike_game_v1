#ifndef bag_h
#define bag_h

#include "healthIncreaseItem.h"
#include "damageIncreaseItem.h"
#include <vector>
#include <memory>
#include "baseItem.h"

class Bag{
public:

    /**
      NAME:
        GetItems()

      SYNOPSIS:
        std::vector<std::shared_ptr<baseItem>> & GetItems();
      DESCRIPTION:
        Returns a refrence to all items being stored.

      RETURNS:
        std::vector<std::shared_ptr<baseItem> & GetItems();

      AUTHOR:
        Josh Long
    */
    std::vector<std::shared_ptr<baseItem>> & GetItems();

    /**
      NAME:
        AddItem

     SYNOPSIS:
       void AddItem(std::shared_ptr<baseItem> a_item);
                    std::shared_ptr<baseItem> a_item -> pointer to object being added to player inventory.

     DESCRIPTION:
       Adds an item object to the storage.

    AUTHOR:
      Josh Long
    */
    void AddItem(std::shared_ptr<baseItem> a_item);

public:
    // MEMBER VARIABLES //
    std::vector<std::shared_ptr<baseItem>> m_itemStorage;
};

#endif
