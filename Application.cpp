//
//  Application.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "Application.h"

Application::Application(){
    // set the frame rate for the window
    //standard_window.setFramerateLimit(30);
    // initlize the app with each menu that will be needed
    std::unique_ptr<MenuState> menu = std::make_unique<MenuState>(standard_window);
    states.newPanel(std::move(menu));
}

void Application::startGame(){
    states.getCurrentPanel().initilize();
    while(standard_window.isOpen()){
        sf::Event event;
        while (standard_window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                // Someone closed the window- bye
                standard_window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && states.getCurrentPanel().getState() == GameState::states::PlayState){
                states.newPanel(std::make_unique<MenuState>(standard_window));
                states.nextPanel();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && states.getCurrentPanel().getState() == GameState::states::MenuState){
                states.newPanel(std::make_unique<PlayState>(standard_window));
                states.nextPanel();
            }
        }

        states.nextPanel();
        states.update();
        states.draw();
    }
}
