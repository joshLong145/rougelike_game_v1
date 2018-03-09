#include "damageIncreaseItem.h"

damageIncreaseItem::damageIncreaseItem():baseItem(){
}

int damageIncreaseItem::getStatModifier(){
    return m_stateModifier;
}

std::string damageIncreaseItem::getItemName(){
    return m_itemName;
}

baseItem::items damageIncreaseItem::itemType(){
    return baseItem::items::damageIncrease;
}

