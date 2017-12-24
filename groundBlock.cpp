//
//  groundBlock.cpp
//  game_proj
//
//  Created by josh long on 2/2/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "groundBlock.h"

//pass arguments from child to parent ( might be a better way to do this )
groundBlock::groundBlock(int xpos, int ypos) : enviormentBlocks(xpos, ypos){
    // initilie texture for the block
    setImage( "dirt.png" );

}

sf::Sprite groundBlock::loadImage(){
    return sprite;
}

void groundBlock::setImage(std::string image_path){
    texture.loadFromFile(image_path);
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

void groundBlock::initilizeSprite(){
    sprite.setTextureRect(sf::IntRect(0,0,65,70));
    sprite.setPosition(x_pos,y_pos);
}

sf::FloatRect groundBlock::getRect(){
    return sprite.getGlobalBounds();
}

