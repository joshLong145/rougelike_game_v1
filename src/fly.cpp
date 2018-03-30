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
    m_texture.loadFromFile("./resources/Black_Fly.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x_val,y_val);
    velocity = v;
}

//main action for enemy ( changes from enemy to enemy)
//Fly will move towards to player at a constant speed
void fly::Move(Player &a_player, sf::Time deltaTime){
    float factor = 0.f;
    const float speed = .1f * velocity;
    factor += deltaTime.asSeconds() * speed;

    if(PathLength(a_player.LoadImage().getPosition().x, a_player.LoadImage().getPosition().y, x_val, y_val) < 300){
        m_sprite.setPosition(Interpolate(m_sprite.getPosition(), a_player.LoadImage().getPosition(),factor));
    }else{
        if(m_angle > 360){
            m_angle -= 360;
        }
        m_angle += speed + 100; // 100 was found to be a good constant to increment by to get nice circles
        m_sprite.move(sin(m_angle), cos(m_angle));
    }
}

//Used to "guess" the next position of movment based on given coords.
 sf::Vector2f fly::Interpolate(const sf::Vector2f point_A, const sf::Vector2f point_B, float factor){
        if(factor > 0.1f){
            factor =  1.0f;
        }else if(factor < 0.f){
            factor = 0.f;
        }

        return point_A * (1.0f - (float)factor) + point_B * factor;
}

void fly::Bounce(sf::Vector2f objBounds){
    if(m_sprite.getPosition().x > objBounds.x){
        m_sprite.move(1,0);
    }else{
        m_sprite.move(-1,0);
    }
    if(m_sprite.getPosition().y > objBounds.y){
        m_sprite.move(0,1);
    }else{
        m_sprite.move(0,-1);
    }
}
