//
//  Bullet.cpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "Bullet.h"
#include "ResourcePath.hpp"
#include "bulletMovingState.h"

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

Bullet::Bullet(int x_start, int y_start, int dir){
    x_pos = x_start;
    y_pos = y_start;
    // direction the bullet will be going
    direction = dir;
    // attempt to load sprite sheet, if failed return error
    texture.loadFromFile("bullets.png");

    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

sf::Sprite Bullet::loadImage(){
    //image_x and image_y are positios on the sprite sheet
    sprite.setTextureRect(sf::IntRect(0,30,25,30));
    return sprite;
}

void Bullet::move(){
    if(direction == EAST){
        sprite.move(velocity,0);
        distance += velocity;
    }
    if(direction == WEST){
        sprite.move(-velocity,0);
        distance += velocity;
    }
    if(direction == NORTH){
        sprite.move(0,velocity);
        distance += velocity;
    }
    if(direction == SOUTH){
        sprite.move(0,-velocity);
        distance += velocity;
    }
}

int Bullet::getDistance(){
    return distance;
}
