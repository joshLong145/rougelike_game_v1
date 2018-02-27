//
//  MenuState.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "MenuState.h"
#include <iostream>
#include "PlayState.h"

MenuState::MenuState(sf::RenderWindow &w) : GameState(w){
    font.loadFromFile("./resources/sansation.ttf");
    //initilizing font and text for menu items
    display.setFont(font);
    display.setPosition({150,10});
    display.setString("ISSAC RIP OFF \n Press space to start");
}

void MenuState::initilize(){
    window.create(sf::VideoMode::getDesktopMode(), "game", sf::Style::Resize);
    sf::View view;
    view.setCenter(view.getSize().x / 4, view.getSize().y / 2);
    window.setView(view);
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // set the frame rate to 30 constant.
}

void MenuState::update(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        applicationManager::addPanel(GameState::states::PlayState);
    }
}

void MenuState::draw(){
    window.clear();
    window.draw(display);
    window.display();
}

bool MenuState::nextPanel(){
    return next;
}

void MenuState::setNext(bool n){
    next = n;
}

GameState::states MenuState::getState(){
    return GameState::states::MenuState;
}
