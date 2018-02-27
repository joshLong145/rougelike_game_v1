//
//  Ghost.cpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "turret.h"
#include "checkCollision.h"

Turret::Turret(int x_pos, int y_pos,const int v):baseEnemy(x_pos,y_pos,v){
    texture.loadFromFile("./resources/turret.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
    sprite.setTextureRect(sf::IntRect(image_x,image_y,50,50));
}

sf::Sprite Turret::loadImage(){
    return sprite;
}

int Turret::getHealth(){
    return health;
}

void Turret::setHealth(int newAmount){
    health  = newAmount;
}

void Turret::move(Player &p, sf::Time deltaTime){
    setBulletDirection();
}

void Turret::bounce(sf::Vector2f objBounds){}

void Turret::hitNonWallObj(){}

bool Turret::isWallHit(){
    return true;
}

bool Turret::setWallHit(bool result){
    return true;
}

int Turret::getVelocity(){
    return velocity;
}

int Turret::path_length(int x1, int y1, int x2, int y2){
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

std::vector<std::unique_ptr<enemyBullet>> & Turret::getBulletVector(){
    return bullets;
}

void Turret::setBulletDirection(){

     if (bullet_clock.getElapsedTime().asSeconds() > 1.f){
        std::unique_ptr<enemyBullet> bullet1 = std::make_unique<enemyBullet>(loadImage().getPosition().x,loadImage().getPosition().y,0);
        std::unique_ptr<enemyBullet> bullet2 = std::make_unique<enemyBullet>(loadImage().getPosition().x,loadImage().getPosition().y,1);
        std::unique_ptr<enemyBullet> bullet3 = std::make_unique<enemyBullet>(loadImage().getPosition().x,loadImage().getPosition().y,2);
        std::unique_ptr<enemyBullet> bullet4 = std::make_unique<enemyBullet>(loadImage().getPosition().x,loadImage().getPosition().y,3);
        bullets.push_back(std::move(bullet1));
        bullets.push_back(std::move(bullet2));
        bullets.push_back(std::move(bullet3));
        bullets.push_back(std::move(bullet4));
        bullet_clock.restart();
    }


}
