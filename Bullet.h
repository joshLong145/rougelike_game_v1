//
//  Bullet.hpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef Bullet_h
#define Bullet_h

#include <SFML/Graphics.hpp>
#include "gameObjectStateManager.h"

class Bullet{
    // public class functions
    public:
        // initilizes the obj with starting pos
        Bullet(int x, int y, int dir);
        // destructor
        ~Bullet() = default;
        // returns a sprite at each location of the bullet ( need to change this but sprites are cheap)
        sf::Sprite loadImage();
        // moves sprite to location clicked
        void move();
        // find the distance the bullet has moved
        int getDistance();
        void incDistance(int d);
        int getVelocity();
        int getDirection();
        void updateStates();
    // private vars for the class
    private:
    // used to move the bullets position.
        int x_pos;
        int y_pos;
        // var to store direction of the bullet
        int direction;
        // velocity for the bullet
        int velocity = 7;
        // var to store distance traveled
        int distance;
        // var for spritesheet
        sf::Texture texture;
        // sprite obj
        sf::Sprite sprite;
        //bool to check animation is at the end
        bool animation_done = false;
        gameObjectStateManager states;
};


#endif
