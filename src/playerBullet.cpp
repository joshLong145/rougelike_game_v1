//
//  Bullet.cpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "playerBullet.h"

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

playerBullet::playerBullet(const int a_xStart, const int a_yStart, int a_dir) : baseBullet(a_xStart, a_yStart, a_dir){
    m_xPos = a_xStart;
    m_yPos = a_yStart;
    // direction the bullet will be going
    m_direction = a_dir;
    m_texture.loadFromFile("./resources/bullets.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_xPos, m_yPos);
    //image_x and image_y are positios on the sprite sheet
    m_sprite.setTextureRect(sf::IntRect(0,30,32,32));
    // Scale the image down by a factor of 20 % for better game feel.
    m_sprite.setScale({.8f,.8f});
}

void playerBullet::move(sf::Time a_deltaTime){
    const auto speed = a_deltaTime.asSeconds() * 200;
    sf::Vector2f pos = LoadImage().getPosition();
    if(m_direction == EAST){
        m_sprite.setPosition(pos.x + speed,pos.y);
        m_distance += speed;
    }

    if(m_direction == WEST){
        m_sprite.setPosition(pos.x - speed,pos.y);
        m_distance += speed;
    }

    if(m_direction == NORTH){
        m_sprite.setPosition(pos.x,pos.y + speed);
        m_distance += speed;
    }

    if(m_direction == SOUTH){
        m_sprite.setPosition(pos.x,pos.y - speed);
        m_distance += speed;
    }
}

int playerBullet::GetDistance(){
    return m_distance;
}
