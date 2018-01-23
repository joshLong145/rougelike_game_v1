//
//  fly.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef fly_h
#define fly_h

#include <stdio.h>
#include "baseEnemy.h"
#include "Player.h"
#include <math.h>

class fly : public baseEnemy{
public:
    fly(int x_pos, int y_pos, int v);
    ~fly(){};
    // returns a sprite obj
    sf::Sprite loadImage();
    // moves enemy
    void move(Player &p, sf::Time deltaTime);
    //called when collision is made with a wall or rock obj
    void bounce(sf::Vector2f objBounds);
    // called when enemy hits a player
    void bounceEnemy();
    // get health
    int getHealth();

    void setHealth(int newAmount);

    bool isWallHit();

    int getVelocity();

    std::vector<std::unique_ptr<enemyBullet>> & getBulletVector();

    int path_length(int x1, int y1, int x2, int y2);

    void setBulletDirection();

    void hitNonWallObj();

    sf::Vector2f interpolate(const sf::Vector2f point_A, const sf::Vector2f point_B, float factor);

private:
    int health = 1;

};


#endif /* fly_hpp */
