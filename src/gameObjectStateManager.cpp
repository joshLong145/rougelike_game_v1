#include "gameObjectStateManager.h"

// move new states to the back
void gameObjectStateManager::NewPanel(const std::shared_ptr<gameObjectState> state){
    m_states.push(std::move(state));
}

void gameObjectStateManager::NextPanel(){
    if(m_states.size() > 0 ){
      if(GetCurrentPanel().nextPanel() ){
            m_states.pop();
      }
    }
}

gameObjectState & gameObjectStateManager::GetCurrentPanel(){
    return *m_states.front();
}

void gameObjectStateManager::UpdatePanels(){
    if(m_states.size() > 0){
      GetCurrentPanel().update();
    }
}

