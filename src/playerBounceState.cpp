#include "playerBounceState.h"

playerBounceState::playerBounceState(Player &p, const sf::Time deltaTime) : gameObjectState(){
    m_player = &p;
    delta = deltaTime;
}

void playerBounceState::update(){
    // calcualtes knock back distance when colliding with enemies
    const auto knock_back = delta.asSeconds() * 50;
      if((m_player->GetPos()[0] == -1 && m_player->GetPos()[1] == 0) ){
        m_player->LoadImage().move(knock_back, 0);

      }else if((m_player->GetPos()[0] == 1 && m_player->GetPos()[1] == 0)){
        m_player->LoadImage().move(-knock_back, 0);

      }else if( (m_player->GetPos()[0] == 0 && m_player->GetPos()[1] == 1) ){
        m_player->LoadImage().move(0, knock_back);

      }else if((m_player->GetPos()[0] == 0 && m_player->GetPos()[1] == -1) ){
        m_player->LoadImage().move(0,-knock_back);
      }
     next = true;
}

bool playerBounceState::nextPanel(){
    return next;
}
