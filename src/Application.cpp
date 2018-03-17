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
        manager.NewPanel(std::make_unique<MenuState>(standard_window));

        //Initilize the first panel
        manager.GetCurrentPanel().InitilizeGameState();

        while(standard_window.isOpen()){
            sf::Event event;
            while (standard_window.pollEvent(event)){

                if (event.type == sf::Event::Closed){
                    // Someone closed the window- bye
                    standard_window.close();
                }
            }
            // Checks if it is time for a new Panel to be processed.
            manager.InitilizeNewPanel();
            // Updates the assets in the current panel.
            manager.Update();
            // Draws all sprites in the current panel.
            manager.draw();
        }
    }

    inline void moveToNextPanel(){
        // Set the current panel m_next to true and moves to the next panel in queue.
        manager.GetCurrentPanel().SetNextPanel(true);

        manager.InitilizeNewPanel();
    }
  // TODO: change from an enum to a unique ptr to the new state (better architrure for current design).
    void addPanel(const GameState::m_states state){
        if(state == GameState::m_states::MenuState){
         manager.NewPanel(std::move(std::make_unique<MenuState>(standard_window)));
         moveToNextPanel();
        }

        if(state == GameState::m_states::PlayState){
            manager.NewPanel(std::make_unique<PlayState>(standard_window));
            moveToNextPanel();
        }
    }

    void addAndSaveCurrentPanel(const GameState::m_states state){
        if(state == GameState::m_states::MenuState){
            manager.NewPanel(std::make_unique<MenuState>(standard_window));
            moveToNextPanel();
        }

        if(state == GameState::m_states::PlayState){
            manager.NewPanel(std::make_unique<PlayState>(standard_window));
            moveToNextPanel();
        }
        if(state == GameState::m_states::PauseState){
           manager.NewPanel(std::make_unique<pauseState>(standard_window));
           manager.RequeuePanel();

        }
    }
}

