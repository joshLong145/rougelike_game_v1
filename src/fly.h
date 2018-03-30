//
//  fly.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef fly_h
#define fly_h

#include <stdio.h>
#include "baseEnemy.h"
#include "Player.h"
#include <math.h>

#define PI 3.14159265

class fly : public baseEnemy{

public:

  /*
    NAME:
      fly

    SYNOPSIS:
      fly(int a_xPos, int a yPos, int velocity);
          int a_xPos -> x position for the fly object in the room.
          int a_yPos -> y position for the fly object in the room.
          int vecloity -> speed of the fly.

    DESCRIPTION:
      Initlizes the fly object and initlizes needed textures and sprite.

    RETURNS:
      None

     AUTHOR:
       Josh Long
   */
   fly(int x_pos, int y_pos, int v);

   /*
     NAME:
       fly

     SYNOPSIS:
       ~fly() = default;

     DESCRIPTION:
       Destroys the fly object.

     RETURNS:
       None

     AUTHOR:
       Josh Long
   */
    ~fly() = default;

    /*
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

   /*
     NAME:
       Bounce

     SYNOPSIS:
       void Bounce(const sf::Vector2f a_objBounds);
            const sf::Vector2f a_objBounds -> a 2-d vector containg the position of the colided object. 

     DESCRIPTION:
       Called when a fly collides with a bounded object. moves fly away fro msaid object.

     RETURNS:
       None

     AUTHOR:
       Josh Long
   */  
    void Bounce(sf::Vector2f objBounds);

    /*
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

    /*
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

     /*
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
    inline baseEnemy::enemyType GetEnemyType() { return baseEnemy::enemyType::fly; }

    /*
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
    int m_health = 2;
    float m_angle = 20 * PI / 180;

};


#endif /* fly_hpp */
