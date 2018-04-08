//
//  Ghost.cpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "Ghost.h"
#include "checkCollision.h"

Ghost::Ghost(const int x_pos, const int y_pos, const int v) : baseEnemy(x_pos,y_pos,v){
    m_texture.loadFromFile("./resources/ghost_enemy.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_xVal,m_yVal);
    m_sprite.setTextureRect(sf::IntRect(m_imageX,m_imageY,40,40));
}

void Ghost::Move(Player &a_player, const sf::Time a_deltaTime){
    if(m_wallHit){
        m_sprite.setPosition(m_sprite.getPosition().x + (m_velocity * a_deltaTime.asSeconds()),m_sprite.getPosition().y);
    }else{
        m_sprite.setPosition(m_sprite.getPosition().x - (m_velocity * a_deltaTime.asSeconds()),m_sprite.getPosition().y);
    }

    if(PathLength(a_player.LoadImage().getPosition().x, a_player.LoadImage().getPosition().y, m_xVal, m_yVal) < 150){
        SetBulletDirection();
    }
}

void Ghost::Bounce(const sf::Vector2f a_objBounds){
    if(m_wallHit){
        // probably should change this soon!!!!!
        m_sprite.setPosition(m_sprite.getPosition().x - (m_velocity / 10), m_sprite.getPosition().y);
    }else{
         m_sprite.setPosition(m_sprite.getPosition().x + (m_velocity / 10), m_sprite.getPosition().y);
    }
    m_wallHit = !m_wallHit;
}

void Ghost::SetBulletDirection(){
     if (m_bulletClock.getElapsedTime().asSeconds() > 0.5){
        std::unique_ptr<enemyBullet> bullet1 = std::make_unique<enemyBullet>(LoadImage().getPosition().x, LoadImage().getPosition().y,0);
        std::unique_ptr<enemyBullet> bullet2 = std::make_unique<enemyBullet>(LoadImage().getPosition().x, LoadImage().getPosition().y,1);
        std::unique_ptr<enemyBullet> bullet3 = std::make_unique<enemyBullet>(LoadImage().getPosition().x, LoadImage().getPosition().y,2);
        std::unique_ptr<enemyBullet> bullet4 = std::make_unique<enemyBullet>(LoadImage().getPosition().x, LoadImage().getPosition().y,3);
        m_bullets.push_back(std::move(bullet1));
        m_bullets.push_back(std::move(bullet2));
        m_bullets.push_back(std::move(bullet3));
        m_bullets.push_back(std::move(bullet4));
        m_bulletClock.restart();
    }
}
