//
//  Application.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "Application.h"

namespace applicationManager{

    void startGame(){
        //Add the first state of the game to the menu state.
        manager.newPanel(std::make_unique<MenuState>(standard_window));
        //Initilize the first panel
        manager.getCurrentPanel().initilize();

        while(standard_window.isOpen()){
            sf::Event event;
            while (standard_window.pollEvent(event)){

                if (event.type == sf::Event::Closed){
                    // Someone closed the window- bye
                    standard_window.close();
                }
            }

            manager.nextPanel();
            manager.update();
            manager.draw();
        }
    }

    inline void moveToNextPanel(){
        manager.getCurrentPanel().setNext(true);
        manager.nextPanel();
    }

    void addPanel(const GameState::states state){
        if(state == GameState::states::MenuState){
         manager.newPanel(std::move(std::make_unique<MenuState>(standard_window)));
         moveToNextPanel();
        }

        if(state == GameState::states::PlayState){
            manager.newPanel(std::make_unique<PlayState>(standard_window));
            moveToNextPanel();
        }
    }

    void addAndSaveCurrentPanel(const GameState::states state){
        if(state == GameState::states::MenuState){
            manager.newPanel(std::make_unique<MenuState>(standard_window));
            moveToNextPanel();
        }

        if(state == GameState::states::PlayState){
            manager.newPanel(std::make_unique<PlayState>(standard_window));
            moveToNextPanel();
        }
        if(state == GameState::states::PauseState){
           manager.newPanel(std::make_unique<pauseState>(standard_window));
           manager.requeuePanel();

        }
    }
}

