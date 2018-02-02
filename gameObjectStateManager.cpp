#include "gameObjectStateManager.h"

// move new states to the back of the qeue
void gameObjectStateManager::newPanel(std::shared_ptr<gameObjectState> state){
    states.push(std::move(state));
}

void gameObjectStateManager::nextPanel(){
    if(states.size() > 0 ){
     if(getCurrentPanel().nextPanel() && stateTimer.getElapsedTime().asSeconds() > .01f){
            states.pop();
            stateTimer.restart();
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


