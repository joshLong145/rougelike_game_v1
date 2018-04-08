#include "playerBulletMultiFireState.h"
#include "playerBulletMultiFire.h"

playerBulletMultiFireState::playerBulletMultiFireState(Player &p, const int a_dir) : gameObjectState(){
  m_player = &p;
  m_direction = a_dir;
}

void playerBulletMultiFireState::update(){ 
  sf::Vector2f pos = m_player->LoadImage().getPosition();
 
 if(m_direction == 3){
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction,  -145));
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction,   -120));
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction,   45));  
  }else if(m_direction == 2){
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction, 145));
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction, 120));
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction, -45)); 
  }else{
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction, 45));
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction, 0));
    m_player->GetBulletVector().push_back(std::make_unique<playerBulletMultiFire>(pos.x,pos.y,m_direction, -45)); 
  }
  
  next = true;
}

bool playerBulletMultiFireState::nextPanel(){
  return next;
}

