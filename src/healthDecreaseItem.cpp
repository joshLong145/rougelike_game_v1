#include "healthDecreaseItem.h"

healthDecreaseItem::healthDecreaseItem():baseItem(){
  m_sprite.setTextureRect(sf::IntRect(0,0,50,50)); 
}

baseItem::items healthDecreaseItem::ItemType(){
  return baseItem::items::healthDecrease;
}
