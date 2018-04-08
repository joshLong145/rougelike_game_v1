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
    this->m_direction = direction;
}
