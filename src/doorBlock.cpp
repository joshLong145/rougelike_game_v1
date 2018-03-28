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
    SetImage("./resources/door.png");
    this->direction = direction;
}

int doorBlock::getDirection(){
    return direction;
}

sf::FloatRect doorBlock::GetRect(){
    return sprite.getGlobalBounds();
}
