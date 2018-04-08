//
//  baseEnemy.hpp
//  game_proj
//
//  Created by josh long on 4/10/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef baseEnemy_h
#define baseEnemy_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "gameObjectStateManager.h"
#include "enemyBullet.h"
#include <memory>
#include "Player.h"

class baseEnemy : public sf::Transformable{
    public:
        enum enemyType{
            fly,
            ghost,
            turret
        };
        /*
          NAME:
            baseEnemy

          SYNOPSIS:
            baseEnemy::baseEnemey(int a_xPos, int a_yPos, int a_velocity)
            int a_xPos -> x position for the enemy object.
            int a_yPos -> y position for the enemy object.

          DESCRIPTION:
            initlizes a new enemy with the desired texture at the specified position
            and with a specific velocity.
          RETURNS:
            None
          AUTHOR:
         m_   Josh Long
        */
        baseEnemy(const int a_xPos, const int a_yPos, const int a_velocity){
            m_xVal = a_xPos;
            m_yVal = a_yPos;
            m_velocity = a_velocity;
        }

        /*
          NAME:
            baseEnemy

          SYNOPSIS:
            baseEnemey::~baseEnemy() = default;

          DESCRIPTION: 
            initlizes a default destructor for all enemiy objects.

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */ 
        ~baseEnemy() = default;

        /*
          NAME:
            LoadImage

          SYNOPSIS:
            inline sf::Sprite LoadImage();

          DESCRIPTION:
            Returns a sprite that can be rendered / manipulated.

          RETURNS:
            sf::Sprite see sfml framework docs for more info.
          AUTHOR:
          Josh Long
        */
        inline sf::Sprite LoadImage(){ return m_sprite; }

        /*
          NAME:
            Move
          SYNOPSIS:
            virtual void baseEnemy();

          DESCRIPTION:
            Performs all manipulation and movement of enemies, specfic for each enemy. 

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */
        virtual void Move(Player &a_player, const sf::Time a_deltaTime) = 0;

        /*
          NAME:
            Bounce

          SYNOPSIS:
            baseEnemy::Bounce(sf::Vector2f a_objectBounds);
            a_objectBounds -> a 2-d vector of the collided objects position, see sfml framework docs for detials.

          DESCRIPTION:
            moves enemy away from the object that was collided with

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */ 
        virtual void Bounce(sf::Vector2f a_objectBounds) = 0;

        /*
          NAME:
            GetHealth

          SYNOPSIS:
            baseEnemy::GetHealth();

          DESCRIPTION:
            Gives the current health of an enemy.

          RETURNS:
            int

          AUTHOR:
          Josh Long
        */ 
        virtual int GetHealth() = 0;

        /*
          NAME:
           SetHealth

          SYNOPSIS:
            baseEnemy::SetHealth(const int a_newAmount);

          DESCRIPTION:
            Assigns a new amount to the enemies current health.

          RETURNS:
            None

          AUTHOR:
          Josh Long
        */ 
        virtual void SetHealth(int a_newAmount) = 0;

        /*
          NAME:
           GetBulletVector

          SYNOPSIS:
            virtual std::vector<std::unique_ptr<enemyBullet>> & GetBulletVector();

          DESCRIPTION:
            Returns a refrence to a vector of enemyBullet objects.
          RETURNS:
           sf::vector<std::unique_ptr<enemyBullet>>

          AUTHOR:
          Josh Long
        */ 
        inline std::vector<std::unique_ptr<enemyBullet>> & GetBulletVector(){ return m_bullets; };

        /*
          NAME:
            PathLength

          SYNOPSIS:
            inline int baseEnemey::PathLength(int x1, int y1, int x2, int y2);

          DESCRIPTION:
            finds the distance between two positions.

          RETURNS:
            int

          AUTHOR:
          Josh Long
        */ 
        inline int PathLength( const int a_x1, const int a_y1, const int a_x2, const int a_y2){
          return std::abs(a_x1 - a_x2) + std::abs(a_y1 - a_y2);
        }

        /*
          NAME:
            GetDamageAmount

          SYNOPSIS:
            inline int  baseEnemey:GetDamageAmount();

          DESCRIPTION:
            returns the amount of damage enemy can assign.

          RETURNS:
           int

          AUTHOR:
          Josh Long
        */ 
        inline int GetDamageAmount(){ return m_damage; }

        /*
          NAME:
            GetEnemeyType

          SYNOPSIS:
           virtual enemyType GetEnemeyType();

          DESCRIPTION:
            Returns an enum of enemyType corepsonding to the specific enemy object.

          RETURNS:
            enemyType

          AUTHOR:
          Josh Long
        */ 
        virtual enemyType GetEnemyType() = 0;

    protected:
        bool m_wallHit = true;
        int m_xVal;
        int m_yVal;
        int m_velocity;
        int m_imageX = 0;
        int m_imageY = 0;
        int m_health = 1;
        int m_damage = 1;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Clock animation_clock;
        std::vector<std::unique_ptr<enemyBullet>> m_bullets;
};





#endif /* baseEnemy_hpp */
