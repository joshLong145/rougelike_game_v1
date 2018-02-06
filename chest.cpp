#include "chest.h"

chest::chest(int x, int y, std::shared_ptr<baseItem> item){
    x_val = x;
    y_val = y;
    texture.loadFromFile("Chest.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
    m_item = item;
}



sf::Sprite chest::loadImage(){
    return sprite;
}

std::shared_ptr<baseItem> chest::getItemStored(){
    return m_item;
}
