#pragma once

#include <stdio.h>
#include "baseEnemy.h"
#include "Player.h"
#include <math.h>

#define PI 3.14159265

class bossOne : public baseEnemy{

public:

  /**
    NAME:
      bossOne

    SYNOPSIS:
      boseOne(int a_xPos, int a yPos, int velocity);
          int a_xPos -> x position for the fly object in the room.
          int a_yPos -> y position for the fly object in the room.
          int vecloity -> speed of the fly.

    DESCRIPTION:
      Initlizes the bossOne object and initlizes needed textures and sprite.

    RETURNS:
      None

     AUTHOR:
       Josh Long
   */
   bossOne(int x_pos, int y_pos, int v);

   /**
     NAME:
       bossOne

     SYNOPSIS:
       ~bossOne() = default;

     DESCRIPTION:
       Destroys the bossOne object.

     RETURNS:
       None

     AUTHOR:
       Josh Long
   */
    ~bossOne() = default;

    /**
      NAME:
        Move

      SYNOPSIS:
       void Move(Player $p, const sf::Time a_deltaTime)

      DESCRIPTION:
        Moves the fly obj based on the current position of the player and elapsed time.
        interpolates the distance to the player and moves slowly to it.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */ 
    void Move(Player &p, sf::Time deltaTime);

    /**
      NAME:
        Bounce

      SYNOPSIS:
        void Bounce(const sf::Vector2f a_objBounds);
            const sf::Vector2f a_objBounds -> a 2-d vector containg the position of the colided object. 

      DESCRIPTION:
        Called when a bossOne collides with a bounded object. moves bossOne away from said object.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    void Bounce(sf::Vector2f objBounds);

    /**
      NAME:
        GetHealth

      SYNOPSIS:
        int GetHealth();

      DESCRIPTION:
        returns the health of the player at the current moment.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    int GetHealth(){ return m_health; }

    /**
      NAME:
        SetHealth

      SYNOPSIS:
        void SetHealth(const int a_newAmount);
             const int a_newAmount -> value for health to be assigned to.
      DESCRIPTION:
        reassigns the value for health to a_newAmount.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
     void SetHealth(const int a_newAmount){
      m_health = a_newAmount;
    }

     /**
       NAME:
         GetEnemyType

       SYNOPSIS:
         inline baseEnemy::enemyType GetEnemyType();

       DESCRIPTION:
         Initlizes the fly object and initlizes needed textures and sprite.

       RETURNS:
         None

       AUTHOR:
         Josh Long
     */
    inline baseEnemy::enemyType GetEnemyType() { return baseEnemy::enemyType::bossOne; }

    /**
      NAME:
        Interpolate

      SYNOPSIS:
        sf::Vector2f Interpolate(const sf::Vecto2f a_point_A, const sf::Vector2f a_pont_B float a_factor);
                     const sf::Vector2f a_point_A -> a 2-D vector that holds the current point of the fly
                     const sf::Vector2f a_point_B -> a 2-D vector that holds the current point of the object
                     being compared with.
                     float a_factor -> the speed at which the fly will move to a_point_B
      DESCRIPTION:
        Moves the fly object towrds a point in a linear fashion.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    sf::Vector2f Interpolate(const sf::Vector2f point_A, const sf::Vector2f point_B, float factor);

private:
    int m_health = 20;
    int m_angle = 20 * PI / 180;
};
