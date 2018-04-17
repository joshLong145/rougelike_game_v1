//
//  MenuState.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "pauseState.h"

pauseState::pauseState(sf::RenderWindow &w) : GameState(w){
    m_font.loadFromFile("./resources/sansation.ttf");
    //initilizing font and text for menu items
    m_display.setFont(m_font);
    m_display.setPosition({150,10});
    m_display.setString("PAUSED \n press U to unpause \n O for options");
}

void pauseState::InitilizeGameState(){
    m_window.create(sf::VideoMode::getDesktopMode(), "game", sf::Style::Resize);
    sf::View view;
    view.setCenter(view.getSize().x / 4, view.getSize().y / 2);
    m_window.setView(view);
    m_window.setFramerateLimit(60); // set the frame rate to 30 constant.
}

void pauseState::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        m_next = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
        m_display.setString("OPTIONS \n press w for window seetings. \n press s for sound settings.");
    }

}

void pauseState::DrawAssets(){
    m_window.clear();
    m_window.draw(m_display);
    m_window.display();
}

GameState::m_states pauseState::GetState(){
    return GameState::m_states::MenuState;
}
