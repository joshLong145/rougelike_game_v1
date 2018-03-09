//
//  Ghost.hpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef Turret_h
#define Turret_h

#include <stdio.h>
#include "baseEnemy.h"
#include "gameObjectStateManager.h"

class Turret: public baseEnemy{
    public:
        Turret(int x_pos, int y_pos,const int v);
        ~Turret() = default;
        // returns a sprite obj
        sf::Sprite loadImage();
        // moves enemy
        void move(Player &p, sf::Time deltaTime);
        //called when collision is made with a wall or rock obj
        void bounce(sf::Vector2f objBounds);
        // called when enemy hits a player
        void hitNonWallObj();
        // get health
        int getHealth();

        void setHealth(int newAmount);

        bool isWallHit();

        bool setWallHit(bool result);

        int getVelocity();

        int path_length(int x1, int y1, int x2, int y2);

        void setBulletDirection();

        inline baseEnemy::enemyType getEnemyType() { return baseEnemy::enemyType::ghost; }

        // returns a refrence to vector of bullet obj
        std::vector<std::unique_ptr<enemyBullet>> & getBulletVector();
    private:
        sf::Clock bullet_clock;
        int health = 7;
};

#endif /* Turret_hpp */