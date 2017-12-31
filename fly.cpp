//
//  fly.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "fly.h"


fly::fly(int x_pos, int y_pos, int v):baseEnemy(x_pos, y_pos, v){
    texture.loadFromFile("Black_Fly.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
    velocity = v;
}

sf::Sprite fly::loadImage(){
    sprite.setTextureRect(sf::IntRect(image_x,image_y,19,12));
    dt = clock.restart();
    return sprite;
}

int fly::getHealth(){
    return health;
}

//main action for enemy ( changes from enemy to enemy)
//Fly will move towards to player at a constant speed
void fly::move(Player &p){
    dt = mainTimer.restart();
    float factor = 0.f;
    float speed = .1f * velocity;
    factor += dt.asSeconds() * speed;
    sprite.setPosition(interpolate(sprite.getPosition(),p.loadImage().getPosition(),factor));
}

//Used to "guess" the next position of movment based on given coords.
 sf::Vector2f fly::interpolate(const sf::Vector2f point_A, const sf::Vector2f point_B, float factor){
        if(factor > 1.f){
            factor = 1.f;
        }else if(factor < 0.f){
            factor = 0.f;
        }
        return point_A +(point_B - point_A) * factor;
}

int fly::getVelocity(){return velocity;}

void fly::bounce(){
    sprite.move(-(velocity * dt.asSeconds()), -(velocity * dt.asSeconds()));
}

void fly::bounceEnemy(){}

bool fly::isWallHit(){ return false; }

int fly::path_length(int x1, int y1, int x2, int y2){ return 0;}

std::vector<std::unique_ptr<enemyBullet>> & fly::getBulletVector(){ return bullets; }

void fly::setBulletDirection(){}

void fly::hitNonWallObj(){}



