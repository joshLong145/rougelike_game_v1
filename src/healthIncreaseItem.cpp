#include "healthIncreaseItem.h"

healthIncreaseItem::healthIncreaseItem():baseItem(){}

int healthIncreaseItem::getStatModifier(){
    return m_stateModifier;
}

std::string healthIncreaseItem::getItemName(){
    return m_itemName;
}

baseItem::items healthIncreaseItem::itemType(){
    return baseItem::items::healthIncrease;
}
