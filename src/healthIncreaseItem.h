#ifndef healthIncreaseItem_h
#define healthIncreaseItem_h

#include "baseItem.h"

class healthIncreaseItem : public baseItem{
public:

    /**
      NAME:
        healthIncreaseItem

      SYNOPSIS:
        healthIncreaseItem();

      DESCRIPTION:
        Initilizes a new healthIncreaseItem obj take no params.

     RETURNS:
       None

     AUTHOR:
       Josh Long
    */
    healthIncreaseItem();

    /**
      NAME:
      GetStatModifier

      SYNOPSIS:
      int GetStatModifier();

      DESCRIPTION:
      returns the stat modification correpsonding to the object.

      RETURNS:
      integer

      AUTHOR:
      Josh Long
    */
    int GetStatModifier() { return m_statModifier; }

    /**
      NAME:
        ItemType

      SYNOPSIS:
        item ItemType();

      DESCRIPTION:
        Returns the type of the item of the correpsonding object.
        so in this case healthIncrease is returned.

      RETURNS:
        item -> enum of all items present within the game.

      AUTHOR:
        Josh Long
    */
    items ItemType();

private:
    int m_statModifier = 5;

};
#endif
