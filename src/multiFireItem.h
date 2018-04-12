#ifndef multiFireItem_h
#define multiFireItem_h

#include "baseItem.h"

class multiFireItem : public baseItem{
public:

    /*
      NAME:
        multiFireItem

      SYNOPSIS:
        healthIncreaseItem();

      DESCRIPTION:
        Initilizes a new multiFireItem obj take no params.

     RETURNS:
       None

     AUTHOR:
       Josh Long
    */
    multiFireItem();

    ~multiFireItem() = default;

    /*
      NAME:
      GetStatModifier

      SYNOPSIS:
      int GetStatModifier();

      DESCRIPTION:
      returns the stat modification correpsonding to the object.

      RETURNS:
        bool

      AUTHOR:
      Josh Long
    */ 
    int GetStatModifier() { return m_statModifier; }

    /*
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
    bool m_statModifier = true;

};
#endif
