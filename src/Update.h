#ifndef Update_h
#define Update_h

#include "Player.h"
#include "baseEnemy.h"
#include "doorBlock.h"
#include "rockBlock.h"
#include "chest.h"
#include <memory>

class Update{
    public:
        /*
          NAME:
            Update

          SYNOPSIS:
            Update() = defualt;

          DESCRIPTION:
            Initlixes an object of the class with a default constructor

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        Update() = default;

        /*
          NAME:
            UpdatePlayerObjs

          SYNOPSIS:
            void UpdatePlayerObjs(Player &a_player, std::vector<sf::Sprite> a_rects, std::vector<std::unique_ptr<baseEnemy> &a_enemies,
                                  std::vector<std::shared_ptr<doorBlock>> a_doorRects, std::vector<std::shared_ptr<chest>> a_chests,
                                  std::vector<sf::Sprite> a_enviormentRocks, sf::Time a_deltaTime)

                                  Player &a_player -> refrence to player object used for all manipulation of player member data.
                                  std::vector<sf::Sprite> a_rects -> all static enviorment blocks, used for collision detection.
                                  std::vector<std::unique_ptr<baseEnemy> &a_enemies -> refrence to all enemies objects being checked.
                                  std::vector<std::shared_ptr<doorBlock>> a_doorRects -> all doors within current area.
                                  std::vector<std::shared_ptr<<chest>> a_chests -> all chest objects within area.
                                  std::vector<sf::Sprite> a_enviormentRocks -> all rock objects withn area.
                                  sf::Time a_deltaTime -> time elapsed since last update (used to sync with current frames)
         DESCRIPTION:
           updates the player object in relation to its enviroment. Gets called once every update cycle
           which is about 60 times a second.

         RETURNS:
           None

         AUTHOR:
           Josh Long
        */ 
        void UpdatePlayerObjs(Player &a_player, std::vector<sf::Sprite> &a_rects, std::vector<std::unique_ptr<baseEnemy>> &a_enemy,
                              std::vector<std::shared_ptr<doorBlock>> &a_doorRects, std::vector<std::shared_ptr<chest>> &a_chests,
                              std::vector<std::shared_ptr<rockBlock>> &a_enviormentRocks, sf::Time a_deltaTime);
        /*
          NAME:
            UpdateEnemyObjs

          SYNOPSIS:
            void UpdateEnemyObjs(std::vector<std::vector<std::unique_ptr<baseEnemy>> &a_enemy, std::vector<sf::Sprite> a_enviormentRocks
                               std::vector<sf::Sprite> a_rects, Player &a_player, sf::Time a_deltaTime)

          DESCRIPTION:
            Updates all enemy objects in relation to its enviroment. Gets called once every update cycle.
            Approx 60 times a second. 

          AUTHOR:
            Josh Long
        */

        void UpdateEnemeyObjs(std::vector<std::unique_ptr<baseEnemy>> &a_enemy, std::vector<std::shared_ptr<rockBlock>> a_enviormentRocks,
                              std::vector<sf::Sprite> a_rects, Player &a_player, sf::Time a_deltaTime);

};

#endif /* Update_hpp */
