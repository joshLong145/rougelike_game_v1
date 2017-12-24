//
//  Bullet.cpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "playerBullet.h"
#include "ResourcePath.hpp"
#include "bulletMovingState.h"

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

playerBullet::playerBullet(int x_start, int y_start, int dir) : baseBullet(x_start,y_start,dir){
    x_pos = x_start;
    y_pos = y_start;
    // direction the bullet will be going
    direction = dir;
    texture.loadFromFile("bullets.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

sf::Sprite playerBullet::loadImage(){
    //image_x and image_y are positios on the sprite sheet
    sprite.setTextureRect(sf::IntRect(0,30,32,32));
    return sprite;
}

void playerBullet::move(){
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

int playerBullet::getDistance(){
    return distance;
}
