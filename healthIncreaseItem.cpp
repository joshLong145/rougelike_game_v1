#include "healthIncreaseItem.h"

healthIncreaseItem::healthIncreaseItem():baseItem(){
    m_sprite.setTextureRect(sf::IntRect(0,0,30,35));
}

sf::Sprite healthIncreaseItem::loadImage(){
    return m_sprite;
}

int healthIncreaseItem::getStatModifier(){
    return m_stateModifier;
}

std::string healthIncreaseItem::getItemName(){
    return m_itemName;
}
