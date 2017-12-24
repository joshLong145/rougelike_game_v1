//
//  doorBlock.hpp
//  game_proj
//
//  Created by josh long on 5/28/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef doorBlock_h
#define doorBlock_h
#pragma once
#include <stdio.h>

#endif /* doorBlock_hpp */

#include "enviormentBlocks.h"
class doorBlock : public enviormentBlocks{
public:
    doorBlock(int xpos, int ypos,int direction);
    void draw(sf::RenderWindow &window);
    sf::Sprite loadImage();
    void setImage(std::string image_path);
    void initilizeSprite();
    sf::FloatRect getRect();
    int getDirection();
private:
    sf::Texture texture;
    int direction = -1;
};
