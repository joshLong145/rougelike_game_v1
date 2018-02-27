#include "healthIncreaseItem.h"

healthIncreaseItem::healthIncreaseItem():baseItem(){
    m_texture.loadFromFile("./resources/health_icon.png");
    m_sprite.setTextureRect(sf::IntRect(0,0,32,32));
    m_sprite.setTexture(m_texture);
}

int healthIncreaseItem::getStatModifier(){
    return m_stateModifier;
}

std::string healthIncreaseItem::getItemName(){
    return m_itemName;
}

baseItem::items healthIncreaseItem::itemType(){
    return baseItem::items::healthIncrease;
}
