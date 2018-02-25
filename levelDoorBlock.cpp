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
    setImage("levelDoor.png");
    this->direction = direction;
}

sf::Sprite levelDoorBlock::loadImage(){
    return sprite;
}

int levelDoorBlock::getDirection(){
    return direction;
}

void levelDoorBlock::setImage(std::string image_path){
    texture.loadFromFile(image_path);
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

void levelDoorBlock::initilizeSprite(){
    sprite.setTextureRect(sf::IntRect(0,0,65,70));
    sprite.setPosition(x_pos,y_pos);
}

sf::FloatRect levelDoorBlock::getRect(){
    return sprite.getGlobalBounds();
}
