//
//  PlayState.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef PlayState_h
#define PlayState_h

#include "GameState.h"
#include <queue>
// class for checking collision with other objects
#include "Update.h"
// for GUI
#include "GUI.h"
//handle file io
#include "levelConfiguration.h"

#include "Application.h"

#include "MenuState.h"
// for unique and shared pointers
#include <memory>

class PlayState : public virtual GameState{
    public:
        PlayState(sf::RenderWindow &a_windowObj);
        void update();

        void InitilizeGameState();

        /*
          NAME:
            UpdateGameObjects

          SYNOPSIS:
            GameState::updateGameObjects();

          DESCRIPTION:
            moves and manipulates all sprites/ assets within the current State. is called in every update cycle.
            Uses functions from the Update class used to update both the player and all enemies within the current room.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void UpdateGameObjects();
        /*
          NAME:
            CheckRoomTransition

          SYNOPSIS:
            GameState::CheckRoomTransition();

          DESCRIPTION:
            if a door has been hit by the player check which kind of door was hit and update the player accordingly.
            there are 3 kinds of a door, a door that brings you forward to the next room, a door that brings you back to the last room
            and a door that brings you to the next level.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void CheckRoomTransition();

        //FOLLOWING FUNCTIONS ARE INHERITED FROM THE GAMESATE BASE CLASS, SEE GameState.h for documentation.
        void DrawAssets();

        m_states GetState();

        void SetMainClock();

    private:
        //iteration vars;
        int m_current_level = 1;
        int m_current_room = 0;
        //containers for level creation
        std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> m_levels;
        // player object
        Player m_player = *new Player(75,75);
        //create a update obj which will detect collision between player and other obj (also checks collision of bullets from the player)
        Update m_update_objects;
        // object for GUI
        GUI gui;
};
#endif /* PlayState_hpp */
