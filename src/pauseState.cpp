//
//  MenuState.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "pauseState.h"

pauseState::pauseState(sf::RenderWindow &w) : GameState(w){
    font.loadFromFile("sansation.ttf");
    //initilizing font and text for menu items
    display.setFont(font);
    display.setPosition({150,10});
    display.setString("PAUSED \n press U to unpause \n O for options");
}

void pauseState::initilize(){
    window.create(sf::VideoMode::getDesktopMode(), "game", sf::Style::Resize);
    sf::View view;
    view.setCenter(view.getSize().x / 4, view.getSize().y / 2);
    window.setView(view);
    window.setFramerateLimit(60); // set the frame rate to 30 constant.
}

void pauseState::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        next = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
        display.setString("OPTIONS \n press w for window seetings. \n press s for sound settings.");
    }

}

void pauseState::draw(){
    window.clear();
    window.draw(display);
    window.display();
}

bool pauseState::nextPanel(){
    return next;
}

void pauseState::setNext(bool n){
    next = n;
}

GameState::states pauseState::getState(){
    return GameState::states::MenuState;
}
