#include "gameObjectStateManager.h"

// move new states to the back
void gameObjectStateManager::newPanel(const std::shared_ptr<gameObjectState> state){
    states.push(std::move(state));
}

void gameObjectStateManager::nextPanel(){
    if(states.size() > 0 ){
      if(getCurrentPanel().nextPanel() ){
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

