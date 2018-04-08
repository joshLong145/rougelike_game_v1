//
//  loadLevel.hpp
//  game_proj
//
//  Created by josh long on 1/31/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef loadLevel_h
#define loadLevel_h

#include "Player.h"
#include "baseEnemy.h"
#include "groundBlock.h"
#include "wallBlock.h"
#include "rockBlock.h"
#include "doorBlock.h"
#include "levelDoorBlock.h"
#include "chest.h"
#include <memory>

/*
renders each room of the game. all textures that could potentially be used are rendered during obj initialization.
player object is passed by refrence to the object.
display() and update() update any object on the screen and display will display any objects to the window which is passed by refrence to display().
*/

class loadLevel{
    public:
        /*
          NAME:
            loadLevel

          SYNOPSIS:
            loadLevel::loadLevel(std::vector<std::string> rooms, std:vector<std::unique_ptr<baseEnemy> &e);
            std::vector<std::string> rooms -> a vector of strings where each character in each string correpsond to a game tile.
            std::vector<std::unique_ptr<baseEnemy> &e -> a refrence to unique_ptrs that are a variety of enemies all inheriting from
            the baseEnemy class.

          DESCRIPTION:
            Initlizes the tiles used in the respected room, which is loaded in from the rooms vector of strings. looks at each character loads the corresponding
            tile needed. Allows for dynamic loading of assets and customs levels.
            Also takes in a vector of enemy objects that will be contained within the room.

         RETURNS:
           None

         AUTHOR:
           Josh Long
        */
        loadLevel(std::vector<std::string> rooms, std::vector<std::unique_ptr<baseEnemy>> &e);
        /*
          NAME:
            SetPlayer

          SYNOPSIS:
            loadLevel::SetPlayer(Player &a_player);
            &a_player -> a refrence to a player object that is passed to room to room by refrence for performance reasons.

          DESCRIPTION:
            Used to change the location of the player to the corresponding room they are loading into.
            Object is passed by refrence to decrease bloat and thus, increase performance.

          RETURNS:
            None

        */
        void SetPlayer(Player &a_player);

        /*
          NAME:
            Display

         SYNOPSIS:
           loadLevel::Display();

         DESCRIPTION:
           renders all sprites within the object. is called every update cycle (approx 60 times a second).

         RETURNS:
           None

         AUTHOR:
           Josh Long
        */
        void Display(sf::RenderWindow &a_windowObj);

        /*
          NAME:
           Update

          SYNOPSIS:
            loadLevel::Update();

          DESCRIPTION:
            updates all assets within the object that have been repositioned in the corresponding cycle.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void update();

         /*
           NAME:
             GetRects

           SYNOPSIS:
             std::vector<std::unique_ptr<baseEnemy>> & loadLevel::GetRects();

           DESCRIPTION:
             Returns a vector of sf:Sprites that correpsond to static(non moving) objects within the room.

           RETURNS:
            std::vector<sf:Sprite> -> static room objects.

            AUTHOR:
              Josh Long
         */
        std::vector<sf::Sprite> & GetRects();

        /*
          NAME:
           GetEnemies

          SYNOPSIS:
           std::vector<std::unique_ptr<baseEnemy>> & loadLevel::GetEnemies();

          DESCRIPTION:
            Returns a refrence to the enemies contained the object.

          AUTHOR:
            Josh Long
        */
        std::vector<std::unique_ptr<baseEnemy>> & GetEnemies();

        /*
           NAME:
             GetDoors

           SYNOPSIS:
             std::vector<std::shared_ptr<doorBlock>> & GetDoors();

           DESCRIPTION:
             Returns a refrence to a vector of unique_ptrs of door objects to be used for collision checking

           RETURNS:
             std::vector<std::unique_ptr<doorBlock>>

           AUTHOR:
             Josh Long
        */
        std::vector<std::shared_ptr<doorBlock>> & GetDoors();

        /*
          NAME:
            ~GetEnviormentRocks

          SYNOPSIS:
            std::vector<std::shared_ptr<rockBlock>> & GetEnviormentRocks();

          DESCRIPTION:
           returns a refrence to a vector of sprites correpsonding to static game sprites
           ( would be contained within GetRects but these have special collision rules).

          RETURNS:
            std::vector<std::shared_ptr<rockBlock>> 

          AUTHOR:
            Josh Long
        */
        std::vector<std::shared_ptr<rockBlock>> & GetEnviormentRocks();

        /*
          NAME:
            GetChests

          SYNOPSIS:
            std::vector<std::shared_ptr<chest>> & GetChests();

          DESCRIPTION:
           Returns a vector of all item chests within the object.

          RETURNS:
            std::vector<std::shared_ptr<chest>>

          AUTHOR:
            Josh Long
        */
        std::vector<std::shared_ptr<chest>> & GetChests();
    private:
        Player *m_player = nullptr;
        //stores enviorment blocks for the room
        std::vector<std::shared_ptr<enviormentBlocks>> m_levelBlocks;
        // all static enviorment objects.
        std::vector<sf::Sprite> m_rects;
        std::vector<std::shared_ptr<rockBlock>> m_rockRects;
        //container for handling door collisions
        std::vector<std::shared_ptr<doorBlock>> m_doorRects;
        std::vector<std::shared_ptr<levelDoorBlock>> m_levelDoorRects;
        //stores enemies for the given room
        std::vector<std::unique_ptr<baseEnemy>> m_enemies;
        // stores chests that are within the room
        std::vector<std::shared_ptr<chest>> m_chests;
};

#endif /* loadLevel_hpp */
