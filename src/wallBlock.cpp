//
//  wallBlock.cpp
//  game_proj
//
//  Created by josh long on 2/3/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "wallBlock.h"

//pass arguments from child to parent ( might be a better way to do this )
wallBlock::wallBlock(int a_xPos, int a_yPos) : enviormentBlocks(a_xPos, a_yPos){
    // initilie texture for the block
    SetImage("./resources/rock.png");
}
