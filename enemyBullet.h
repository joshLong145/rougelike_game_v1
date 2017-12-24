//
//  Bullet.hpp
//  game_proj
//
//  Created by josh long on 1/30/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef  enemyBullet_h
#define  enemyBullet_h

#include <SFML/Graphics.hpp>
#include "gameObjectStateManager.h"
#include "baseBullet.h"

class enemyBullet : public baseBullet{
    // public class functions
    public:
        // initilizes the obj with starting pos
        enemyBullet(int x, int y, int dir);
        // destructor
        ~enemyBullet() {}
        // returns a sprite at each location of the bullet ( need to change this but sprites are cheap)
        sf::Sprite loadImage();
        // moves sprite to location clicked
        void move();
};


#endif
