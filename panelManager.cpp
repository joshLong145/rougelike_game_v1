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
        if(!states.front()->isInit()){
            states.front()->initilize();
            states.front()->init();
        }else{
            //if the playstate has been suspended, then we need to reinitlize the game clock
            if(states.front()->getState() == GameState::states::PlayState){
                states.front()->setMainTimer();
            }
        }
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

void panelManager::requeuePanel(){
    states.push(std::move(states.front()));
    states.pop(); // pops the refrence to the state that we just requed off of the queue
}

