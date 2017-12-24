//
//  groundBlock.hpp
//  game_proj
//
//  Created by josh long on 2/2/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef groundBlock_h
#define groundBlock_h

#include "enviormentBlocks.h"
class groundBlock : public enviormentBlocks{
    public:
        groundBlock(int xpos, int ypos);
        void draw(sf::RenderWindow &window);
        sf::Sprite loadImage();
        void setImage(std::string image_path);
        void initilizeSprite();
        sf::FloatRect getRect();
    private:
        sf::Texture texture;
};




#endif /* groundBlock_hpp */
