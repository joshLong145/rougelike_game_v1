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
        /*
          NAME:
            playerBullet

          SYNOPSIS:
            playerBullet(const int a_xStart, const int a_yStart, const int a_dir);
                         const int a_xStart -> x position on the x axis during initlization.
                         const int a_yStart -> y position on the y axis during initlization.
                         const int a_dir -> direction bullet object will head in.

          DESCRIPTION:
            Initlizes a playerBullet object at the desired x,y position with the desired direction.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        playerBullet(const int a_xStart, const int a_yStart, const int a_dir);

        /*
          NAME:
            ~playerBullet

          SYNOPSIS:
            ~playerBullet() = default;

          DESCRIPTION:
            Initlizes a destructor for the playerBullet obj.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        ~playerBullet() = default;

        /*
          NAME:
            move

          SYNOPSIS:
            void move(sf::Time a_deltaTime);
                      sf::Time a_deltaTime -> time since last update, used to sync actions with current frame.

          DESCRIPTION:
            Accelerates the playerBullet object in the appropriate direction.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void move(sf::Time deltaTime);

        /*
          NAME:
            GetDistance

          SYNOPSIS:
            int GetDistance();

          DESCRIPTION:
            Returns the distance that the bullet has traveled in it's lifetime.

          RETURNS:
            int

          AUTHOR:
            Josh Long
        */
        int GetDistance();
};

#endif
