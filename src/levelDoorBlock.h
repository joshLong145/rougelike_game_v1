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
    levelDoorBlock(int xpos, int ypos,int direction);
    void draw(sf::RenderWindow &window);
    void SetImage(std::string image_path);
    void InitilizeSprite();
    sf::FloatRect GetRect();
    int getDirection();
private:
    sf::Texture texture;
    int direction = -1;
};

#endif /* doorBlock_hpp */
