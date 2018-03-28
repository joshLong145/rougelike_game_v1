//
//  groundBlock.cpp
//  game_proj
//
//  Created by josh long on 2/2/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "groundBlock.h"

//pass arguments from child to parent ( might be a better way to do this )
groundBlock::groundBlock(int a_x, int a_y) : enviormentBlocks(a_x, a_y){
    // initilie texture for the block
    SetImage( "./resources/dirt.png" );
}
