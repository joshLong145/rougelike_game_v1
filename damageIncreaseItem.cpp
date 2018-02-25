#include "damageIncreaseItem.h"

damageIncreaseItem::damageIncreaseItem():baseItem(){
    m_texture.loadFromFile("attack_item_icon.png");
    m_sprite.setTextureRect(sf::IntRect(0,0,32,32));
    m_sprite.setTexture(m_texture);
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

