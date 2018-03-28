#ifndef healthDecreaseItem_h
#define healthDecreaseItem_h

#include "baseItem.h"

class healthDecreaseItem : public baseItem{
 public:

  /*

   */
  healthDecreaseItem();

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

 private:
  int m_statModifier = 2;

};
#endif
