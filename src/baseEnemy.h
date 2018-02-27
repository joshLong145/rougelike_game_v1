//
//  baseEnemy.hpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef baseEnemy_h
#define baseEnemy_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "../ResourcePath.hpp"
#include "gameObjectStateManager.h"
#include "enemyBullet.h"
#include <memory>
#include "Player.h"

class baseEnemy : public sf::Transformable{
    public:
        enum enemyType{
            fly,
            ghost
        };

        baseEnemy(int x_pos, int y_pos, const int v){
            x_val = x_pos;
            y_val = y_pos;
            velocity = v;
        }

        ~baseEnemy() = default;

        // returns a sprite obj
        virtual sf::Sprite loadImage() = 0;
        // moves enemy ( based on AI path )

        virtual void move(Player &p, sf::Time deltaTime) = 0;

        //called when collision is made with a wall or rock obj
        virtual void bounce(sf::Vector2f objectBounds) = 0;

        //used when interacting with player
        virtual void hitNonWallObj() = 0;

        // get health
        virtual int getHealth() = 0;

        //set value of health to a new object
        virtual void setHealth(int newAmount) = 0;

        // determins of a wall has been hit by the enemy
        virtual bool isWallHit() = 0;

        virtual int getVelocity() = 0;

        virtual std::vector<std::unique_ptr<enemyBullet>> & getBulletVector() = 0;

        virtual int path_length(int x1, int y1, int x2, int y2) = 0;

        inline int getDamageAmount(){ return damage; }

        virtual enemyType getEnemyType() = 0;

    protected:
        int x_val;
        int y_val;
        int velocity;
        int image_x = 0;
        int image_y = 0;
        int health = 1;
        int damage = 1;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock animation_clock;
        std::vector<std::unique_ptr<enemyBullet>> bullets;
};





#endif /* baseEnemy_hpp */
