//
//  panelManger.cpp
//  game_proj
//
//  Created by josh long on 5/7/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "panelManager.h"

void PanelManager::newPanel(std::unique_ptr<GameState> state){
    states.push(std::move(state));
}

void PanelManager::nextPanel(){
    if(getCurrentPanel().nextPanel()){
        states.pop();
        states.front()->initilize();
    }
}

GameState & PanelManager::getCurrentPanel(){
    return *states.front();
}

bool PanelManager::switchPanel(){
    return false;
}

void PanelManager::update(){
    getCurrentPanel().update();
}

void PanelManager::draw(){
    getCurrentPanel().draw();
}

void PanelManager::deleteData(){

}
