#include "enemyBullet.h"

// defines for each direction a projectile can accelarte in.
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

enemyBullet::enemyBullet(int a_xPos, int a_yPos, int a_dir) : baseBullet(a_xPos,a_yPos,a_dir){
    m_texture.loadFromFile("./resources/bullets.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_xPos,m_yPos);
    //image_x and image_y are positios on the sprite sheet
    m_sprite.setTextureRect(sf::IntRect(0,30, 32, 32));
    m_sprite.setScale({.8f, .8f});
    m_sprite.setColor(sf::Color::Red);
}

void enemyBullet::move(sf::Time a_deltaTime){
    const auto speed = a_deltaTime.asSeconds() * 250;
    sf::Vector2f pos = LoadImage().getPosition();
    if(m_direction == EAST){
        m_sprite.setPosition(pos.x + speed, pos.y);
        m_distance += speed;
    }

    if(m_direction == WEST){
        m_sprite.setPosition(pos.x - speed, pos.y);
        m_distance += speed;
    }

    if(m_direction == NORTH){
        m_sprite.setPosition(pos.x, pos.y + speed);
        m_distance += speed;
    }

    if(m_direction == SOUTH){
        m_sprite.setPosition(pos.x, pos.y - speed);
        m_distance += speed;
    }
}
