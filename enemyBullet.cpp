//
//  Bullet.cpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "enemyBullet.h"
#include "ResourcePath.hpp"
#include "bulletMovingState.h"

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

enemyBullet::enemyBullet(int x, int y, int dir) : baseBullet(x,y,dir){
    texture.loadFromFile("bullets.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
}

sf::Sprite enemyBullet::loadImage(){
    //image_x and image_y are positios on the sprite sheet
    sprite.setTextureRect(sf::IntRect(0,30,32,32));
    return sprite;
}

void enemyBullet::move(sf::Time deltaTime){
    const auto speed = deltaTime.asSeconds() * 250;
    sf::Vector2f pos = loadImage().getPosition();
    if(direction == EAST){
        sprite.setPosition(pos.x + speed,pos.y);
        distance += speed;
    }
    if(direction == WEST){
        sprite.setPosition(pos.x - speed,pos.y);
        distance += speed;
    }
    if(direction == NORTH){
        sprite.setPosition(pos.x,pos.y + speed);
        distance += speed;
    }
    if(direction == SOUTH){
        sprite.setPosition(pos.x,pos.y - speed);
        distance += speed;
    }
}
