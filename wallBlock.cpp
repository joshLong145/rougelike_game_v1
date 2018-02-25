//
//  wallBlock.cpp
//  game_proj
//
//  Created by josh long on 2/3/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "wallBlock.h"
//pass arguments from child to parent ( might be a better way to do this )
wallBlock::wallBlock(int xpos, int ypos) : enviormentBlocks(xpos, ypos){
    // initilie texture for the block
    setImage("rock.png");
}

sf::Sprite wallBlock::loadImage(){
    return sprite;
}

void wallBlock::setImage(std::string image_path){
    texture.loadFromFile(image_path);
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

void wallBlock::initilizeSprite(){
    sprite.setTextureRect(sf::IntRect(0,0,65,70));
    sprite.setPosition(x_pos,y_pos);
}

sf::FloatRect wallBlock::getRect(){
    return sprite.getGlobalBounds();
}
