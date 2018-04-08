#include "playerFireBulletState.h"
#include "playerBulletMultiFire.h"

playerFireBulletState::playerFireBulletState(Player &p, const int a_dir) : gameObjectState(){
  m_player = &p;
  m_direction = a_dir;
}

void playerFireBulletState::UpdateState(){ 
  sf::Vector2f pos = m_player->LoadImage().getPosition();
  m_player->GetBulletVector().push_back(std::make_unique<playerBullet>(pos.x,pos.y,m_direction));
  m_next = true;
}

bool playerFireBulletState::NextPanel(){
  return m_next;
}
 
