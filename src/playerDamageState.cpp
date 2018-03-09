#include "playerDamageState.h"


playerDamageState::playerDamageState(Player &p, int damage) : gameObjectState(){
    player = &p;
    enemyDamage = damage;
}



bool playerDamageState::nextPanel(){
    return next;
}

void playerDamageState::update(){
  player->setDamageColorToggle(true);
  next = true;
}

