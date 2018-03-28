#include "enemyWalkingState.h"

enemyWalkingState::enemyWalkingState(baseEnemy &e) : gameObjectState(){
    enemy = &e;
}

void enemyWalkingState::update(){
}

bool enemyWalkingState::nextPanel(){
    return next;
}
