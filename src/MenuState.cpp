//
//  MenuState.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "MenuState.h"
#include "PlayState.h"

MenuState::MenuState(sf::RenderWindow &w) : GameState(w){
    m_font.loadFromFile("./resources/sansation.ttf");
    //initilizing font and text for menu items
    m_display.setFont(m_font);
    m_display.setPosition({150,10});
    m_display.setString("ISSAC RIP OFF \n Press space to start");
}

void MenuState::InitilizeGameState(){
    m_window.create(sf::VideoMode::getDesktopMode(), "game", sf::Style::Resize);
    sf::View view;
    view.setCenter(view.getSize().x / 4, view.getSize().y / 2);
    m_window.setView(view);
    m_window.setVerticalSyncEnabled(true); // call it once, after creating the window
    m_window.setFramerateLimit(60); // set the frame rate to 30 constant.
}

void MenuState::update(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        applicationManager::addPanel(GameState::m_states::PlayState);
    }
}

void MenuState::DrawAssets(){
    m_window.clear();
    m_window.draw(m_display);
    m_window.display();
}



GameState::m_states MenuState::GetState(){
    return GameState::m_states::MenuState;
}
