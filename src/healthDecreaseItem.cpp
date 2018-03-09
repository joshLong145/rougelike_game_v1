#include "healthDecreaseItem.h"

healthDecreaseItem::healthDecreaseItem():baseItem(){
}

int healthDecreaseItem::getStatModifier(){
  return m_stateModifier;
}

std::string healthDecreaseItem::getItemName(){
  return m_itemName;
}

baseItem::items healthDecreaseItem::itemType(){
  return baseItem::items::healthDecrease;
}
