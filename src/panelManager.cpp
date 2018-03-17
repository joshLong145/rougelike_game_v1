//
//  panelManger.cpp
//  game_proj
//
//  Created by josh long on 5/7/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "panelManager.h"

void panelManager::NewPanel(std::unique_ptr<GameState> state){
    m_states.push(std::move(state));
}

void panelManager::InitilizeNewPanel(){
    if(GetCurrentPanel().NextPanel()){
        m_states.pop();
        if(!m_states.front()->HasBeenInitlized()){
            m_states.front()->InitilizeGameState();
            m_states.front()->SetToInitlized();
        }else{
          //if the playstate has been suspended, then we need to reinitlize the game clock
          if(m_states.front()->GetState() == GameState::m_states::PlayState){
              m_states.front()->SetMainTimer();
          }
        }
    }
}

GameState & panelManager::GetCurrentPanel(){
    return *m_states.front();
}

bool panelManager::SwitchPanel(){
    return false;
}

void panelManager::Update(){
    GetCurrentPanel().update();
}

void panelManager::draw(){
    GetCurrentPanel().DrawAssets();
}

void panelManager::RequeuePanel(){
    m_states.push(std::move(m_states.front()));
    m_states.pop(); // pops the refrence to the state that we just requed off of the queue
}

