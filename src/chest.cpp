#include "chest.h"
#include <stdlib.h>

chest::chest(int x, int y) : enviormentBlocks(x,y){
    setImage("./resources/chestTile.png");
    initilizeSprite();
    int randItem = (rand() % 2) + 1;
    if(randItem == 1){
        m_item = std::make_unique<healthIncreaseItem>();
    }else if(randItem == 2){
        m_item = std::make_unique<damageIncreaseItem>();
    }

}


void chest::setImage(std::string image_path){
    texture.loadFromFile(image_path);
    sprite.setTexture(texture);
}

void chest::initilizeSprite(){
    sprite.setTextureRect(sf::IntRect(0,0,65,70));
    sprite.getTransform().transformRect(sf::FloatRect(0,0,-1,-1));
    sprite.setPosition(x_pos,y_pos);
}

sf::FloatRect chest::getRect(){
    return sprite.getGlobalBounds();
}


sf::Sprite chest::loadImage(){
    return sprite;
}

std::shared_ptr<baseItem> chest::getItemStored(){
    return m_item;
}
