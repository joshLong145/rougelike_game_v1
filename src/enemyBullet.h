#ifndef  enemyBullet_h
#define  enemyBullet_h

#include <SFML/Graphics.hpp>
#include "gameObjectStateManager.h"
#include "baseBullet.h"

class enemyBullet : public baseBullet{
    // public class functions
    public:
        /**
          NAME:
            enemyBullet

          SYNOPSIS:
            enemyBullet(const int a_xPos, const int a_yPos, const int a_dir)
                        const int a_xPos -> position on the x axis when initlized.
                        const int a_yPos -> position on the y axis when initlized.
                        const int a_dir -> direction object will be accelerating in.
          DESCRIPTION:
            Initlization of a enemyBullet object, sets inital x,y position and direction.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        enemyBullet(const int a_xPos, const int a_yPos, const int a_dir);

        /**
          NAME:
            ~enemyBullet

          SYNOPSIS:
            ~enemyBulet();

          DESCRIPTION:
            Initlizes a defualt destructor for the object.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        ~enemyBullet() {}

        /**
          NAME:
            move

          SYNOPSIS:
            void move(sf::Time a_deltaTime);

          DESCRIPTION:
            accelerates enemyBullet object within desired direction.
            every update cycle.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void move(sf::Time deltaTime);
};

#endif
