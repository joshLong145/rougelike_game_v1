#include "playerDamageState.h"


playerDamageState::playerDamageState(Player &p, int damage) : gameObjectState(){
    player = &p;
    enemyDamage = damage;
}



bool playerDamageState::nextPanel(){
    return next;
}

void playerDamageState::update(){
    player->setHealth((player->getHealth() - enemyDamage));
    player->setDamageColorToggle(true);
}

