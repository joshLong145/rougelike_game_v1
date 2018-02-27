//
//  fly.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "fly.h"
#include <math.h>

fly::fly(int x_pos, int y_pos, int v):baseEnemy(x_pos, y_pos, v){
    texture.loadFromFile("./resources/Black_Fly.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
    velocity = v;
}

sf::Sprite fly::loadImage(){
    sprite.setTextureRect(sf::IntRect(image_x,image_y,19,12));
    return sprite;
}

int fly::getHealth(){
    return health;
}

void fly::setHealth(int newAmount){
    health = newAmount;
}

//main action for enemy ( changes from enemy to enemy)
//Fly will move towards to player at a constant speed
void fly::move(Player &p, sf::Time deltaTime){
    float factor = 0.f;
    const float speed = .1f * velocity;
    factor += deltaTime.asSeconds() * speed;

    if(path_length(p.loadImage().getPosition().x, p.loadImage().getPosition().y, x_val, y_val) < 300){
        sprite.setPosition(interpolate(sprite.getPosition(), p.loadImage().getPosition(),factor));
    }else{
        if(angle > 360){
            angle -= 360;
        }
        angle += speed + 100; // 100 was found to be a good constant to increment by to get nice circles
        sprite.move(sin(angle), cos(angle));
    }
}

//Used to "guess" the next position of movment based on given coords.
 sf::Vector2f fly::interpolate(const sf::Vector2f point_A, const sf::Vector2f point_B, float factor){
        if(factor > 0.1f){
            factor =  1.0f;
        }else if(factor < 0.f){
            factor = 0.f;
        }

        return point_A * (1.0f - (float)factor) + point_B * factor;
}

int fly::getVelocity(){ return velocity; }

void fly::bounce(sf::Vector2f objBounds){
    if(sprite.getPosition().x > objBounds.x){
        sprite.move(1,0);
    }else{
        sprite.move(-1,0);
    }
    if(sprite.getPosition().y > objBounds.y){
        sprite.move(0,1);
    }else{
        sprite.move(0,-1);
    }
}

void fly::bounceEnemy(){}

bool fly::isWallHit(){ return false; }

int fly::path_length(int x1, int y1, int x2, int y2){
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

std::vector<std::unique_ptr<enemyBullet>> & fly::getBulletVector(){ return bullets; }


void fly::hitNonWallObj(){}



