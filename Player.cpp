//
//  Player.cpp
//  game_proj
//
//  Created by josh long on 1/28/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "Player.h"
#include "playerWalkingState.h"
#include "playerBounceState.h"
#include <memory>

// load spritesheet within the constructor of the obj
Player::Player(int x_pos, int y_pos){
    x_val = x_pos;
    y_val = y_pos;
    // splice the sprite sheet for the player into IntRect obj (sprites are a standard 32x32)
    for(int col = 0; col < 4; col++){
        for(int row = 0; row < 3; row++){
            animation_frames[col][row] = sf::IntRect(row * 32,col * 32,32,32);
        }
    }
    texture.loadFromFile("playerSpriteSheet.png");
    texture.setSmooth(true);
    // set the initial sprite to
    sprite.setTextureRect(animation_frames[3][2]);
    sprite.setTexture(texture);
    sprite.setPosition(x_val,y_val);
}

sf::Sprite & Player::loadImage(){
    return sprite;
}
int Player::getHealth(){
    return health;
}
int * Player::getPos(){
    return last_move;
}
void Player::setHealth(int h){
    health = h;
}
void Player::setPosition(int x_val, int y_val){
    sprite.setPosition(x_val,y_val);
    this ->x_val = x_val;
    this-> y_val = y_val;
}
void Player::setDoor(int d){
    door = d;
}
int Player::getDoor(){
    return door;
}

void Player::playerControls(){

    // add bullets objs to the vector if left, right, up, or down are pressed, cool down of 1 sec based on internal clock rate of one secound.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(x_val,y_val,2));
            bullet_clock.restart();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(x_val,y_val,3));
            bullet_clock.restart();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(x_val,y_val,1));
            bullet_clock.restart();
        }
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(x_val,y_val,0));
            bullet_clock.restart();
        }
    }
    // push a new walking state onto the event queue when a player presses a movement key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        states.newPanel(*new playerWalkingState('W', *this));
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        states.newPanel(*new playerWalkingState('A', *this));
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        states.newPanel(*new playerWalkingState('S', *this));
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        states.newPanel(*new playerWalkingState('D', *this));
    }
}

void Player::updateWalkingAnimation(char dir){

    if (animation_clock.getElapsedTime().asSeconds() > 0.1f && dir == 'S'){
        image_col = 0;
        if(image_row >= 2){
            image_row = 0;
            sprite.setTextureRect(animation_frames[image_col][image_row]);
        }else{
            image_row++;
            sprite.setTextureRect(animation_frames[image_col][image_row]);
          }
            animation_clock.restart();
    }else if (animation_clock.getElapsedTime().asSeconds() > 0.1f && dir == 'W'){
            image_col = 3;
            if(image_row >= 2){
                image_row = 0;
                sprite.setTextureRect(animation_frames[image_col][image_row]);
            }else{
                image_row++;
                sprite.setTextureRect(animation_frames[image_col][image_row]);
          }

            animation_clock.restart();
    }else if (animation_clock.getElapsedTime().asSeconds() > 0.1f && dir == 'D'){
            image_col = 2;
            if(image_row >= 2){
                image_row = 0;
                sprite.setTextureRect(animation_frames[image_col][image_row]);
            }else{
                image_row++;
                sprite.setTextureRect(animation_frames[image_col][image_row]);
          }
            animation_clock.restart();
    }else if (animation_clock.getElapsedTime().asSeconds() > 0.1f && 'A'){
            image_col = 1;
            if(image_row >= 2){
                image_row = 0;
                sprite.setTextureRect(animation_frames[image_col][image_row]);
            }else{
                image_row++;
                sprite.setTextureRect(animation_frames[image_col][image_row]);
            }
            animation_clock.restart();
    }
}

// collision detection
// gets the x and y values of the obj collided with and determins where on the map it is based on pixel location
void Player::bounce(){
    states.newPanel(*new playerBounceState(*this));
}

void Player::transporForDoor(){
    if(last_move[0] == 1 && last_move[1] == 0){
        loadImage().setPosition(x_val - 480,y_val);
        x_val = loadImage().getPosition().x;
        y_val = loadImage().getPosition().y;
    }
    else if (last_move[0] == -1 && last_move[1] == 0){
        loadImage().setPosition(x_val + 480,y_val);
        x_val = loadImage().getPosition().x;
        y_val = loadImage().getPosition().y;
    }

}
void Player::incY(int val){
    y_val += val;
}

void Player::incX(int val){
    x_val += val;
}

int Player::getY(){
    return y_val;
}

int Player::getX(){
    return x_val;
}
std::vector<std::shared_ptr<playerBullet>> & Player::getBulletVector(){
    return bullets;
}

void Player::clearBullets(){
    while(bullets.size() > 0){
        bullets.pop_back();

    }
}

void Player::updateStates(){
    states.nextPanel();
    states.update();
}
