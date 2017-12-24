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

fly::fly(int x_pos, int y_pos, int v, Player &p):baseEnemy(x_pos,y_pos,v){
    texture.loadFromFile("Black_Fly.png");
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
    velocity = v;
    player = &p;
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
    srand(time(NULL));
    sprite.move(sin(player->getX()) * rand() % 3, sin(player->getY()) * rand() % 3);
}


int fly::getVelocity(){return velocity;}

void fly::bounce(){
    velocity *= -1;
    sprite.move(velocity * 3, velocity * 3);
}

void fly::bounceEnemy(){}

void fly::updateStates(){}

bool fly::isWallHit(){}

int fly::path_length(int x1, int y1, int x2, int y2){}

std::vector<std::unique_ptr<enemyBullet>> & fly::getBulletVector(){ return bullets; }

void fly::setBulletDirection(){}

void fly::hitNonWallObj(){}



