#include "chest.h"

chest::chest(int x, int y){
    x_val = x;
    y_val = y;
    texture.loadFromFile("Chest.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
}

sf::Sprite chest::loadImage(){
    return sprite;
}
