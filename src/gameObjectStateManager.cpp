#include "gameObjectStateManager.h"

// move new states to the back
void gameObjectStateManager::NewPanel(const std::shared_ptr<gameObjectState> a_state){
    m_states.push(std::move(a_state));
}

void gameObjectStateManager::MoveToNextPanel(){
    if(m_states.size() > 0 ){
      if(GetCurrentPanel().NextPanel() ){
            m_states.pop();
      }
    }
}

gameObjectState & gameObjectStateManager::GetCurrentPanel(){
    return *m_states.front();
}

void gameObjectStateManager::UpdatePanels(){
    if(m_states.size() > 0){
      GetCurrentPanel().UpdateState();
    }
}

