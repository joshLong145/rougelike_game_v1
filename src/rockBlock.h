
#ifndef rockBlocks_h
#define rockBlocks_h

#include "enviormentBlocks.h"

class rockBlock : public enviormentBlocks{
public:
    rockBlock(int xpos, int ypos);
     sf::Sprite loadImage();
    void setImage(std::string image_path);
    void initilizeSprite();
    sf::FloatRect getRect();
};

#endif
