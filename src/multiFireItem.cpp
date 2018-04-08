#include "multiFireItem.h"

multiFireItem::multiFireItem():baseItem(){
  m_sprite.setTextureRect(sf::IntRect(50 * 9, 50 * 2,50,50)); 
}

baseItem::items multiFireItem::ItemType(){
  return baseItem::items::multiFire;
}
