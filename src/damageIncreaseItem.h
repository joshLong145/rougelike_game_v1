#ifndef damageIncreaseItem_h
#define damageIncreaseItem_h

#include "baseItem.h"

class damageIncreaseItem : public baseItem{
public:

    /*
      NAME:
        damageIncreaseItem

      SYNOPSIS:
        damageIncreaseItem();

      DESCRIPTION:
        Initlizes a damageIncreaseItem takes no paramaters.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    damageIncreaseItem();

    /*
      NAME:
        ItemType

      SYNOPSIS:
        items ItemType();

      DESCRIPTION:
        Returns an enum that correpsonds to the object.
        used when modifying player states.

      RETURNS:
        enum items-> defined within the base class and has all possible items

      AUTHOR:
        Josh Long
    */ 
    items ItemType();

    /*
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
    int GetStatModifier(){ return m_statModifier; }

private:
    int m_statModifier = 1;

};
#endif
