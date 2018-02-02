//
//  panelManger.cpp
//  game_proj
//
//  Created by josh long on 5/7/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "panelManager.h"

void panelManager::newPanel(std::unique_ptr<GameState> state){
    states.push(std::move(state));
}

void panelManager::nextPanel(){
    if(getCurrentPanel().nextPanel()){
        states.pop();
        states.front()->initilize();
    }
}

GameState & panelManager::getCurrentPanel(){
    return *states.front();
}

bool panelManager::switchPanel(){
    return false;
}

void panelManager::update(){
    getCurrentPanel().update();
}

void panelManager::draw(){
    getCurrentPanel().draw();
}


