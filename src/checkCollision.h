
#ifndef checkCollision_h
#define checkCollision_h

#include <SFML/Graphics.hpp>
#include "baseEnemy.h"
#include "Player.h"
#include "doorBlock.h"
#include "rockBlock.h"
#include <memory>
namespace checkCollision{
        /*
          NAME:
            CheckCollisonWalls

          SYNOPSIS:
            sf::Sprite * CheckCollisonWalls(sf::Sprite obj, std::vector<sf::Sprite> s2);
                                            sf::Sprite obj -> sprite we are checking.
                                            std::vector<sf::Sprite> s2 -> objects we are checking
                                            against.
          DESCRIPTION:
            Checks if an object has collided with any wall objects.

          RETURNS:
            bool

          AUTHOR:
            Josh Long
        */
        sf::Sprite * CheckCollisionWalls(sf::Sprite obj,std::vector<sf::Sprite> s2);

        /*
           NAME:
            CheckCollisionRocks

          SYNOPSIS:
            rockBlock & CheckCollisionRocks(sf::Sprite a_obj, std::vector<rockBlock> a_rocks);
                                            sf::Sprite a_obj -> object being checked against.
                                            std::vector<rockBlock> a_rock -> rockBlock objects being checked for collision.
          DESCRIPTION:
            Checks if a sprite is collding with any rockBlock objects.

          RETURNS:
            rockBlock & -> refrence to rock block object being hit.
            if no rockBlock is hit, return nullptr.

          AUTHOR:
            Josh Long
        */
        bool CheckCollisionRocks(sf::Sprite a_obj, std::vector<std::shared_ptr<rockBlock>> &a_rocks);

        /*
          NAME:
            CheckCollisionPlayerBullets

          SYNOPSIS:
            bool CheckCollisionPlayerBullets(sf::Sprite a_obj, Player &a_player)
                                             sf::Sprite a_obj -> object being checked
                                             Player &a_player -> refrence to a player obj.
          DESCRIPTION:
            Checks collision with any of the player projectile that are currently active.

          RETURNS:
            bool

          AUTHOR:
            Josh Long
        */
        bool CheckCollisionPlayerBullets(sf::Sprite obj,Player &p);

        /*
          NAME:
            CheckCollisionBasic

          SYNOPSIS:
            bool CheckCollisionBasic(sf::Sprite obj1, sf::Sprite obj2);

        */
        bool CheckCollisionBasic(sf::Sprite obj1, sf::Sprite obj2);

        /*
          NAME:
            CheckCollisionEnemies

          SYNOPSIS:
            CheckCollisionEnemies(sf::Sprite obj1, std::vector<std::unique_ptr<baseEnemy>> &a_enemies )
                                  sf::Sprite obj -> sprite that we are checking collison for.
                                  std::vector<std::unique_ptr<baseEnemy>> $a_enemies -> refrence to a list of sprites
                                  to be checked for collision against.
         DESCRIPTION:
           Checks if a sprite has collided with any of the enemy sprites within the current room.

         RETURNS:
           bool

         AUTHOR:
          Josh Long
        */
        bool CheckCollisionEnemies(sf::Sprite a_obj1, std::vector<std::unique_ptr<baseEnemy>> &a_enemies);

        /*
          NAME:
            CheckCollisionEnemyBullets

          SYNOPSIS:
            CheckCollisionEnemyBullet(sf::Sprite obj, std::vector<std::unique_ptr<baseEnemy>> &enemies)
                                     sf::Sprite obj -> object being checked for collision.
                                     sf::<std::unique_ptr<baseEnemy>> &enemies -> objects being checked for collision against.

         DESCRIPTION:
           Checks a sprite object for collision against enemy projectiles.

         RETURNS:
           bool

         AUTHOR:
           Josh Long
        */
        bool CheckCollisionEnemyBullets(sf::Sprite a_obj,std::vector<std::unique_ptr<baseEnemy>> &a_enemies);

        /*
          NAME:
            CheckCollisionDoors

          SYNOPSIS:
            bool CheckCollisionDoors(std::vector<std::shared_ptr<doorBlock>> a_door, Player &a_player);
                                     std::vector<std::shared_ptr<doorBlock>> a_door -> all doors within current room.
                                     Player &a_player -> Refrence to player object

         DESCRIPTION:
           Checks if the player has collided with a door object. If so move forward or back a room.
           depending on the type of door.

        RETURNS:
          bool

        AUTHOR:
          Josh Long
        */
        bool CheckCollisionDoors(std::vector<std::shared_ptr<doorBlock>> a_door,Player &a_player);
}

#endif /* checkCollision_hpp */
