#include "damageIncreaseItem.h"

damageIncreaseItem::damageIncreaseItem():baseItem(){
  m_sprite.setTextureRect(sf::IntRect(50 * 4,50 * 5,50,50)); 
}

baseItem::items damageIncreaseItem::ItemType(){
    return baseItem::items::damageIncrease;
}

