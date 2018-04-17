//
//  Ghost.cpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "turret.h"
#include "checkCollision.h"

Turret::Turret(const int a_xPos, const int a_yPos,const int a_velocity):baseEnemy(a_xPos, a_yPos, a_velocity){
    m_texture.loadFromFile("./resources/turret.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_xVal,m_yVal);
    m_sprite.setTextureRect(sf::IntRect(m_imageX,m_imageY,50,50));
}

void Turret::Move(Player &a_player, sf::Time a_deltaTime){
    SetBulletDirection();
}

void Turret::Bounce(sf::Vector2f a_objBounds){}

void Turret::SetBulletDirection(){

     if(m_bulletClock.getElapsedTime().asSeconds() > 1.f){
        std::unique_ptr<enemyBullet> bullet1 = std::make_unique<enemyBullet>(LoadImage().getPosition().x,LoadImage().getPosition().y,0);
        std::unique_ptr<enemyBullet> bullet2 = std::make_unique<enemyBullet>(LoadImage().getPosition().x,LoadImage().getPosition().y,1);
        std::unique_ptr<enemyBullet> bullet3 = std::make_unique<enemyBullet>(LoadImage().getPosition().x,LoadImage().getPosition().y,2);
        std::unique_ptr<enemyBullet> bullet4 = std::make_unique<enemyBullet>(LoadImage().getPosition().x,LoadImage().getPosition().y,3);
        // Since we are using unique pointers, each one needs to be moved into the vector instead of copied.
        m_bullets.push_back(std::move(bullet1));
        m_bullets.push_back(std::move(bullet2));
        m_bullets.push_back(std::move(bullet3));
        m_bullets.push_back(std::move(bullet4));
        m_bulletClock.restart();
    }


}
