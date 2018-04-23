#include "bossOne.h"

bossOne::bossOne(int x_pos, int y_pos, int v):baseEnemy(x_pos, y_pos, v){
    m_texture.loadFromFile("./resources/boss_1.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_xVal,m_yVal);
    m_velocity = v;
}

//main action for enemy ( changes from enemy to enemy)
//Fly will move towards to player at a constant speed
void bossOne::Move(Player &a_player, sf::Time deltaTime){
    float factor = 0.f;
    const float speed = .1f * m_velocity;
    factor += deltaTime.asSeconds() * speed;

    m_sprite.setPosition(Interpolate(m_sprite.getPosition(), a_player.LoadImage().getPosition(),factor)); 
}

//Used to "guess" the next position of movment based on given coords.
sf::Vector2f bossOne::Interpolate(const sf::Vector2f point_A, const sf::Vector2f point_B, float factor){
        if(factor > 0.1f){
            factor =  1.0f;
        }else if(factor < 0.f){
            factor = 0.f;
        }

        return point_A * (1.0f - (float)factor) + point_B * factor;
}

void bossOne::Bounce(sf::Vector2f objBounds){
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
