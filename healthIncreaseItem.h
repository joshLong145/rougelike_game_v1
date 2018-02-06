#ifndef healthIncreaseItem_h
#define healthIncreaseItem_h

#include "baseItem.h"

class healthIncreaseItem : public baseItem{
public:

    /*

    */
    healthIncreaseItem();

    /*

    */
    ~healthIncreaseItem() = default;

    /*

    */
    int getStatModifier();

    /*

    */
    std::string getItemName();

    /*

    */
    items itemType();

private:
    int m_stateModifier = 5;

};
#endif
