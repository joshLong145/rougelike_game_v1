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

                //check for state transistions and update accordingly
                if(manager.getCurrentPanel().getState() == GameState::states::PlayState &&
                   sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
                    addPanel(GameState::states::MenuState);
                }
                if(manager.getCurrentPanel().getState() == GameState::states::MenuState &&
                   sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    addPanel(GameState::states::PlayState);
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

    void addPanel(GameState::states state){
        if(state == GameState::states::MenuState){
            manager.newPanel(std::make_unique<MenuState>(standard_window));
            moveToNextPanel();
        }

        if(state == GameState::states::PlayState){
            manager.newPanel(std::make_unique<PlayState>(standard_window));
            moveToNextPanel();
        }
    }
}
