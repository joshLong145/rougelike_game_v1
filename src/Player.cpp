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
#include "playerDamageState.h"
#include <memory>

// load spritesheet within the constructor of the obj
Player::Player(int x_pos, int y_pos){
    // splice the sprite sheet for the player into IntRect obj (sprites are a standard 32x32)
    for(int col = 0; col < 4; col++){
        for(int row = 0; row < 3; row++){
            animation_frames[col][row] = sf::IntRect(row * 32,col * 32,32,32);
        }
    }
    texture.loadFromFile("./resources/playerSpriteSheet.png");
    //smooth sprite sheet so edges/pixels are less jaged.
    texture.setSmooth(true);
    // set the initial sprite to
    sprite.setTextureRect(animation_frames[3][2]);
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
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
}
void Player::setDoor(int d){
    door = d;
}
int Player::getDoor(){
    return door;
}

void Player::playerControls(const sf::Time deltaTime){
    sf::Vector2f pos = loadImage().getPosition();

    // add bullets objs to the vector if left, right, up, or down are pressed, cool down of 1 sec based on internal clock rate of one secound.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(pos.x + 10,pos.y,2));
            bullet_clock.restart();
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(pos.x - 10,pos.y,3));
            bullet_clock.restart();
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(pos.x,pos.y - 10,1));
            bullet_clock.restart();
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if (bullet_clock.getElapsedTime().asSeconds() > 0.5){
            bullets.push_back(std::make_unique<playerBullet>(pos.x,pos.y + 10,0));
            bullet_clock.restart();
        }
    }

    // push a new walking state onto the event queue when a player presses a movement key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        states.newPanel(std::make_unique<playerWalkingState>('W', *this, deltaTime));
        // states.getCurrentPanel().setNext(true);
        return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      states.newPanel(std::move(std::make_unique<playerWalkingState>('A', *this, deltaTime)));
        //states.getCurrentPanel().setNext(true);
        return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        states.newPanel(std::make_unique<playerWalkingState>('S', *this, deltaTime));
        //states.getCurrentPanel().setNext(true);
        return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        states.newPanel(std::make_unique<playerWalkingState>('D', *this, deltaTime));
        //states.getCurrentPanel().setNext(true);
        return;
    }
   
}

void Player::evaluateDamage(const int enemyDamage){
    if(m_hit_timer.getElapsedTime().asSeconds() > 1.0f){
      setHealth(health - enemyDamage);
      setDamageColorToggle(true);
      m_hit_timer.restart();
    }
}
// collision detection
// gets the x and y values of the obj collided with and determins where on the map it is based on pixel location
void Player::bounce(const sf::Time deltaTime){
  states.newPanel(std::move(std::make_unique<playerBounceState>(*this, deltaTime)));
   states.getCurrentPanel().setNext(true);
   return;
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

void Player::transporForDoor(){
    sf::Vector2f pos = loadImage().getPosition();
    if(door == 1 || door == 2){
        if(last_move[0] == 1 && last_move[1] == 0){
          sprite.setPosition(pos.x - (65 * 7) - 32,pos.y);
        }
        else if (last_move[0] == -1 && last_move[1] == 0){
          sprite.setPosition(pos.x + (65 * 7) + 32,pos.y);

        }
    }else if(door == 3){
        sprite.setPosition(65 *2 - 32,300);

    }
}

// used for damage calculation for enemies in the update cycle
int Player::getOffensiveValue(){
    return attack;
}
// used for damage calculation for player in the update cycle
int Player::getDefensiveValue(){
    return armor;
}
std::vector<std::shared_ptr<playerBullet>> & Player::getBulletVector(){
    return bullets;
}

Bag & Player::getItemStorage(){
    return m_playerItems;
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

void Player::setDamageColorToggle(bool setting){
    damageColorToggle = setting;
}

void Player::manageColors(){
    if(colorTiming.getElapsedTime().asSeconds() > 1.0f){
        if(damageColorToggle){
            sprite.setColor(sf::Color::Red);
            damageColorToggle = !damageColorToggle;
        }else{
            sprite.setColor(sf::Color::White); //resets the sprite to the original color
        }
        colorTiming.restart();
    }
}

void Player::addItemModifications(){
    for(auto item = m_playerItems.getItems().begin(); item != m_playerItems.getItems().end(); item++){
        if(!(*item)->IsItemUsed()){
            if((*item)->ItemType() == baseItem::items::healthIncrease){
                health += (*item)->GetStatModifier();
                (*item)->SetItemUse(true);
           }
           if((*item)->ItemType() == baseItem::items::damageIncrease){
                attack += (*item)->GetStatModifier();
                (*item)->SetItemUse(true);
           }
           if((*item)->ItemType() == baseItem::items::healthDecrease){
             if(health >= 3){
               health -= (*item)->GetStatModifier();
               (*item) ->SetItemUse(true);
             }else{
               health  = 1;
             }
           }
        }
    }
}



