//
//  Ghost.hpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef Ghost_h
#define Ghost_h

#include <stdio.h>
#include "baseEnemy.h"

class Ghost: public baseEnemy{
    public:
        /*
          NAME:
            Ghost
          SYNOPSIS:
            Ghost::Ghost(const int a_xPos, const int a_yPos, const int velocity);
            const int a_xPos -> x position of the Ghost object.
            const int a_yPos -> y position of the Ghost object.
            const int velocity -> movement speed of the Ghost object.

          DESCRIPTION:
            initlizes a instance of the Ghost, loading the image file to a texture
            and maps it to a sprite member object.

          RETURNS:
            None
          AUTHOR:
            Josh Long
        */
        Ghost(const int a_xPos, int a_yPos,const int velocity);

        /*
          NAME:
            ~Ghost

          SYNOPSIS:
            Ghost::~Ghost() = default;

          DESCRIPTION:
            Initlizes a default destructor for the Ghost object.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */ 
        ~Ghost() = default;

        /*
          NAME:
            Move

          SYNOPSIS:
            void Ghost::Move(Player &a_player, sf::Time a_deltaTime);
            a_player -> a refrence to the player object 

          DESCRIPTION:
            Repositions the sprite object / performs custom actions. 

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */
        void Move(Player &a_player, const sf::Time a_deltaTime);

        /*
          NAME:
            Bounce
          SYNOPSIS:
            Ghost::Bounce

          DESCRIPTION:
            Performs an action once the enemy has

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */ 
        void Bounce(const sf::Vector2f a_objBounds);

        /*
          NAME:
           SetBulletDirection

          SYNOPSIS:
            void Ghost::SetBulletDirection();
           
          DESCRIPTION:
            Initlizes bullets that will move in the specified direction (N,S,E,W).

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */ 
        void SetBulletDirection();

        /*
          NAME:
           GetHealth

          SYNOPSIS:
            int GetHealth();

          DESCRIPTION:
            Returns the current health of the Ghost object.

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
            void SetHealth(const int a_newAmount);
            const int a_newAmount -> number that m_health will be set to.

          DESCRIPTION:
            Sets the health of Ghost to a new value after it has taken damage from the player.

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */ 
        void SetHealth(const int a_newAmount){
          m_health = a_newAmount;
        }

        /*
          NAME:
           GetEnemyType

          SYNOPSIS:
            baseEnemy::enemyType GetEnemyType();

          DESCRIPTION:
            Returns a enum that relates to what kind of enemy this is.
            so in this instance a ghost enum is returned.

          RETURNS:
             baseEnemy::enemyType -> a enum corresponding to enemy type.

          AUTHOR:
          Josh Long
        */ 
        inline baseEnemy::enemyType GetEnemyType() { return baseEnemy::enemyType::ghost; }

  private:
        sf::Clock m_bulletClock;
        int m_health = 3;
};



#endif /* Ghost_hpp */
