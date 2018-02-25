#ifndef damageIncreaseItem_h
#define damageIncreaseItem_h

#include "baseItem.h"

class damageIncreaseItem : public baseItem{
public:

    /*

    */
    damageIncreaseItem();

    /*

    */
    ~damageIncreaseItem() = default;

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
    int m_stateModifier = 1;

};
#endif
