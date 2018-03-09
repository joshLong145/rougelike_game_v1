//
//  Bullet.hpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef playerBullet_h
#define playerBullet_h

#include "baseBullet.h"

class playerBullet : public baseBullet{
    // public class functions
    public:
        // initilizes the obj with starting pos
        playerBullet(int x, int y, int dir);
        ~playerBullet() = default;
        // returns a sprite at each location of the bullet ( need to change this but sprites are cheap)
        sf::Sprite loadImage();
        // moves sprite to location clicked
        void move(sf::Time deltaTime);
        // find the distance the bullet has moved
        int getDistance();
        void incDistance(int d);
        int getVelocity();
        int getDirection();
        void updateStates();
};


#endif
