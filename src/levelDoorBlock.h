//
//  doorBlock.hpp
//  game_proj
//
//  Created by josh long on 5/28/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef levelDoorBlock_h
#define levelDoorBlock_h
#pragma once

#include <stdio.h>
#include "doorBlock.h"

class levelDoorBlock : public doorBlock{
public:
    /*
      NAME:
        levelDoorBlock
      SYNOPSIS:
        levelDoorBlock(const int a_xPos, const int a_yPos, const int a_direction);
                       const int a_xPos -> position on the x axis for the doorBlock
                       const int a_yPos -> position on the y axis for the doorBlock
                       const int a_direction -> direction that door will bring you towards.

      DESCRIPTION:
        Initlizes a doorBlock object at the desired x,y position and direction the door will bring you.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    levelDoorBlock(const int a_xpos, const int ypos, const int direction);

};

#endif /* doorBlock_hpp */
