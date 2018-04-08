#ifndef playerBulletRapidFire_h
#define playerBulletRapidFire_h

#include "playerBullet.h"

class playerBulletMultiFire : public playerBullet{
    // public class functions
    public:
        /*
          NAME:
            playerBulletMultiFire

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
        playerBulletMultiFire(const int a_xStart, const int a_yStart, const int a_dir, const int a_angle);

        /*
          NAME:
            ~playerBulletMultiFire

          SYNOPSIS:
            ~playerBulletFire() = default;

          DESCRIPTION:
            Initlizes a destructor for the playerBullet obj.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        ~playerBulletMultiFire() = default;

        /*
          NAME:
            move

          SYNOPSIS:
            void move(sf::Time a_deltaTime);
                      sf::Time a_deltaTime -> time since last update, used to sync actions with current frame.

          DESCRIPTION:
            Accelerates the playerBullet object in the appropriate direction.

          RETURNS:
            void

          AUTHOR:
            Josh Long
        */
        void move(const sf::Time a_deltaTime);

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

 private:
        int m_angle = 0;
};

#endif
