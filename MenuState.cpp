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
    font.loadFromFile("sansation.ttf");
    //initilizing font and text for menu items
    display.setFont(font);
    display.setPosition({150,10});
    display.setString("ISSAC RIP OFF \n Press space to start");
}

void MenuState::initilize(){
    window.create(sf::VideoMode{500,500},"menu");
}

void MenuState::update(){
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
