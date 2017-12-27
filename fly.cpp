//
//  fly.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "fly.h"
#include <math.h>
#include "time.h"
#include <stdlib.h>

fly::fly(int x_pos, int y_pos, int v, Player &p):baseEnemy(x_pos,y_pos,v){
    texture.loadFromFile("Black_Fly.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
    velocity = v;
    player = &p;
    srand(time(NULL));
}

sf::Sprite fly::loadImage(){
    sprite.setTextureRect(sf::IntRect(image_x,image_y,19,12));
    dt = clock.restart();
    return sprite;
}

int fly::getHealth(){
    return health;
}

void fly::move(){
    sprite.move(sin(x_val + player->getX()) * ((rand() % velocity) + 1), sin(y_val + player->getY()) * ((rand() % velocity) + 1));
}


int fly::getVelocity(){return velocity;}

void fly::bounce(){
    sprite.move(-(velocity * dt.asSeconds()), -(velocity * dt.asSeconds()));
}

void fly::bounceEnemy(){}

void fly::updateStates(){}

bool fly::isWallHit(){ return false; }

int fly::path_length(int x1, int y1, int x2, int y2){ return 0;}

std::vector<std::unique_ptr<enemyBullet>> & fly::getBulletVector(){ return bullets; }

void fly::setBulletDirection(){}

void fly::hitNonWallObj(){}



