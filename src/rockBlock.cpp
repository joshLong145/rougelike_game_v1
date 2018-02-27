#include "rockBlock.h"

rockBlock::rockBlock(int xpos, int ypos) : enviormentBlocks(xpos,ypos){
    setImage("./resources/Blue_rock.png");
}

sf::Sprite rockBlock::loadImage(){
    return sprite;
}

void rockBlock::setImage(std::string image_path){
    texture.loadFromFile(image_path);
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

void rockBlock::initilizeSprite(){
    sprite.setTextureRect(sf::IntRect(0,0,65,70));
    sprite.setPosition(x_pos,y_pos);
}

sf::FloatRect rockBlock::getRect(){
    return sprite.getGlobalBounds();
}
