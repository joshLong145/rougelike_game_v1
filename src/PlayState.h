//
//  PlayState.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef PlayState_h
#define PlayState_h

#include <stdio.h>
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
        PlayState(sf::RenderWindow &w);
        void update();

        void initilize();

        void updateGameObjects();

        void checkRoomTransition();

        void draw();

        bool nextPanel();

        states getState();

        void setNext(bool n);

        void setMainClock();

    private:
        //iteration vars;
        int current_level = 1;
        int current_room = 0;
        //containers for level creation
        std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> levels;
        // player object
        Player player = *new Player(75,75);
        //create a update obj which will detect collision between player and other obj (also checks collision of bullets from the player)
        Update update_objects;
        // object for GUI
        GUI gui;
};
#endif /* PlayState_hpp */
