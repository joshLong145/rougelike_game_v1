//
//  doorBlock.cpp
//  game_proj
//
//  Created by josh long on 5/28/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "doorBlock.h"

doorBlock::doorBlock(int xpos, int ypos,int direction) : enviormentBlocks(xpos, ypos){
    // initilie texture for the block
    setImage("door.png" );
    this->direction = direction;
}

sf::Sprite doorBlock::loadImage(){

    return sprite;
}
int doorBlock::getDirection(){
    return direction;
}
void doorBlock::setImage(std::string image_path){
    texture.loadFromFile(image_path);
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

void doorBlock::initilizeSprite(){
    sprite.setTextureRect(sf::IntRect(0,0,65,70));
    sprite.setPosition(x_pos,y_pos);
}

sf::FloatRect doorBlock::getRect(){
    return sprite.getGlobalBounds();
}
