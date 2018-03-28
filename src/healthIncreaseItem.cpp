#include "healthIncreaseItem.h"

healthIncreaseItem::healthIncreaseItem():baseItem(){
  m_sprite.setTextureRect(sf::IntRect(50 * 8,0,50,50));
 
}
baseItem::items healthIncreaseItem::ItemType(){
    return baseItem::items::healthIncrease;
}
