#include "enemyWalkingState.h"

enemyWalkingState::enemyWalkingState(baseEnemy &e) : gameObjectState(){
    enemy = &e;
}

void enemyWalkingState::update(){
    if(enemy->isWallHit()){
        enemy->loadImage().move(-5,0);
    }else{
        enemy->loadImage().move(5,0);
    }
    next = true;
}

bool enemyWalkingState::nextPanel(){
    return next;
}
