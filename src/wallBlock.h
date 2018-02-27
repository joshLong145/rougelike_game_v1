//
//  wallBlock.hpp
//  game_proj
//
//  Created by josh long on 2/3/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef wallBlock_h
#define wallBlock_h

#include "enviormentBlocks.h"
class wallBlock : public enviormentBlocks{
public:
    wallBlock(int xpos, int ypos);
    sf::Sprite loadImage();
    void setImage(std::string image_path);
    void initilizeSprite();
    sf::FloatRect getRect();
};

#endif /* wallBlock_hpp */
