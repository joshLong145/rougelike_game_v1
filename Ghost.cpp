//
//  Ghost.cpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "Ghost.h"
#include "enemyWalkingState.h"
#include <math.h>

Ghost::Ghost(int x_pos, int y_pos,const int v):baseEnemy(x_pos,y_pos,v){
    texture.loadFromFile( "ghost_enemy.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
    sprite.setTextureRect(sf::IntRect(image_x,image_y,50,50));
}

sf::Sprite Ghost::loadImage(){
    return sprite;
}

int Ghost::getHealth(){
    return health;
}

void Ghost::setHealth(int newAmount){
    health  = newAmount;
}

void Ghost::move(Player &p, sf::Time deltaTime){
    if(isWallHit()){
        sprite.move(velocity * deltaTime.asSeconds(),0);
    }else{
        sprite.move(-(velocity * deltaTime.asSeconds()),0);
    }
}

void Ghost::bounce(sf::Vector2f objBounds){
    if(wallhit){
        // probably should change this soon!!!!!
         sprite.move(-velocity / 10,0);
    }else{
         sprite.move(velocity / 10,0);
    }
    wallhit = !wallhit;
}

void Ghost::hitNonWallObj(){

}

bool Ghost::isWallHit(){
    return wallhit;
}

bool Ghost::setWallHit(bool result){
    wallhit = result;
    return true;
}

int Ghost::getVelocity(){
    return velocity;
}

int Ghost::path_length(int x1, int y1, int x2, int y2){
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

std::vector<std::unique_ptr<enemyBullet>> & Ghost::getBulletVector(){
    return bullets;
}

void Ghost::setBulletDirection(){

     if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
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
