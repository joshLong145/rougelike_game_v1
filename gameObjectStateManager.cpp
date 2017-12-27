#include "gameObjectStateManager.h"

// move new states to the back of the qeue
void gameObjectStateManager::newPanel(gameObjectState &state){
    states.push(std::move(&state));
}

void gameObjectStateManager::nextPanel(){
    if(states.size() > 0){
     if(getCurrentPanel().nextPanel()){
            states.pop();
        }
    }
}

gameObjectState & gameObjectStateManager::getCurrentPanel(){
    return *states.front();
}



void gameObjectStateManager::update(){
    if(states.size() > 0){
        getCurrentPanel().update();
    }
}


