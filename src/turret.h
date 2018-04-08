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

        /**
          NAME:
            Turret

          SYNOPSIS:
             Turret(const int a_xPos, const int a_yPos, const int velocity)
                   const int a_xPos -> position on the x axis when initlized.
                   const int a_yPos -> position on the y axis when initilized.
                   const int velocity -> used for speed calulations of the projectiles created.

          DESCRIPTION:
            Initilizes a turret obj at desired x,y coords and desired speed of created projectiles.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        Turret(const int a_xPos, const int y_pos,const int a_velocity);

        /**
          NAME:
          Turret

          SYNOPSIS:
          ~Turret() = default;

          DESCRIPTION:
          Initlizes default dustructor for new object.

          RETURNS:
          None

          AUTHOR:
          Josh Long
        */ 
       ~Turret() = default;

       /**
         NAME:
         Turret

         SYNOPSIS:
         void Move(Player &a_player, sf::Time a_deltaTime);
         Player &a_player -> refrence to player object, some enemies use this to guage direction.
         Player sf:;TIme a_deltaTime -> global clock to sync all game objects with current frame.

         DESCRIPTION:
         Initlizes projectiles to be fired in all directions every second.

         RETURNS:
         None

         AUTHOR:
         Josh Long
       */
       void Move(Player &a_player, sf::Time a_deltaTime);

       /**
         NAME:
         Turret

         SYNOPSIS:
         void Bounce(const sf::Time a_deltaTime);
                     const sf::TIme a_deltaTime -> amount of time since last update cycle.

         DESCRIPTION:
           Moves the object away from any collidable enviorment pieces.

         RETURNS:
           None

         AUTHOR:
           Josh Long
       */

        void Bounce(sf::Vector2f a_objBounds);

        /**
          NAME:
            GetHealth

          SYNOPSIS:
            int GetHealth();

          DESCRIPTION:
            Returns the amount of the health the turret object current has left.

          RETURNS:
            int

          AUTHOR:
            Josh Long
        */
        int GetHealth(){ return m_health; }

        /*
          NAME:
            SetHealth

          SYNOPSIS:
            SetHealth(const int a_newAmount);
                      cont int a_newAmount -> new value for turrets health.
          DESCRIPTION:
            Sets the health of the turret object to the newly specified amount.

          RETURNS:
           None

          AUTHOR:
           Josh Long
        */
        void SetHealth(int a_newAmount){ m_health = a_newAmount; }

        /*
          NAME:
            SetBulletDirection

          SYNOPSIS:
            void SetBulletDirection();

          DESCRIPTION:
            Initlizes bullet objects and sets corresponding directions.

          RETURNS:
          None

          AUTHOR:
          Josh Long
        */
        void SetBulletDirection();

        /*
          NAME:
            GetEnemyType

          SYNOPSIS:
            inline baseEnemy::enemyType GetEnemyType();

          DESCRIPTION:
            Returns an enum corresponding to the specific enemy.
            So in this case it returns turret
          RETURNS:
          None

          AUTHOR:
          Josh Long
        */
        inline baseEnemy::enemyType GetEnemyType() { return baseEnemy::enemyType::turret; }

        /*
          NAME:
            GetBulletVector

          SYNOPSIS:
            inline std::vectorMstd::unique_ptr<enemyBullet> & GetBulletVector();

          DESCRIPTION:
            Returns a refrence to the bullet objects relating to the turrent.

          RETURNS:
            std::vector<std::unique_ptr<enemyBullet>> &

          AUTHOR:
          Josh Long
        */
        inline std::vector<std::unique_ptr<enemyBullet>> & GetBulletVector(){ return m_bullets; }
    private:
        sf::Clock m_bulletClock;
        int m_health = 7;
};

#endif /* Turret_hpp */
