//
//  doorBlock.cpp
//  game_proj
//
//  Created by josh long on 5/28/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "levelDoorBlock.h"

levelDoorBlock::levelDoorBlock(int xpos, int ypos,int direction) : doorBlock(xpos, ypos, direction){
    // initilie texture for the block
    SetImage("./resources/levelDoor.png");
    this->direction = direction;
}

int levelDoorBlock::getDirection(){
    return direction;
}

void levelDoorBlock::SetImage(std::string image_path){
    texture.loadFromFile(image_path);
    sprite.setTexture(texture);
    sprite.setPosition(m_xPos,m_yPos);
}

void levelDoorBlock::InitilizeSprite(){
    sprite.setTextureRect(sf::IntRect(0,0,65,70));
    sprite.setPosition(m_xPos,m_yPos);
}

sf::FloatRect levelDoorBlock::GetRect(){
    return sprite.getGlobalBounds();
}
