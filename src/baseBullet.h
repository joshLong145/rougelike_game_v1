//
//  Bullet.hpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef baseBullet_h
#define baseBullet_h

#include <SFML/Graphics.hpp>
#include "gameObjectStateManager.h"

class baseBullet : public sf::Transformable{
    // public class functions
    public:
        // initilizes the obj with starting pos
        baseBullet(int x, int y, const int dir){
            x_pos = x;
            y_pos = y;
            // direction the bullet will be going
            direction = dir;
        }
            // destructor
        ~baseBullet() = default;
        // returns a sprite at each location of the bullet ( need to change this but sprites are cheap)
        virtual sf::Sprite loadImage() = 0;
        // moves sprite to location clicked
        virtual void move(sf::Time deltaTime) = 0;
        // private vars for the class
    protected:
        // used to move the bullets position.
        int x_pos;
        int y_pos;
        // var to store direction of the bullet
        int direction;
        // velocity for the bullet
        const int velocity = 7;
        // var to store distance traveled
        int distance;
        // var for spritesheet
        sf::Texture texture;
        // sprite obj
        sf::Sprite sprite;
        //bool to check animation is at the end
        bool animation_done = false;
        //used to calculate speed
        sf::Clock mainTimer;
        sf::Time delta;
};


#endif
