
#include "playerWalkingState.h"

playerWalkingState::playerWalkingState(char b, Player &p) : gameObjectState(){
    button = b;
    player = &p;
}

void playerWalkingState::update(){
    player->updateWalkingAnimation(button);

    if(button == 'S'){
        player->loadImage().move(0,5);
        player->incY(5);
        player->getPos()[0] = 0;
        player->getPos()[1] = -1;

    }

    if(button == 'W'){
        player->loadImage().move(0,-5);
        player->incY(-5);
        player->getPos()[0] = 0;
        player->getPos()[1] = 1;
    }

    if(button == 'A'){
        player->loadImage().move(-5,0);
        player->incX(-5);
        player->getPos()[0] = -1;
        player->getPos()[1] = 0;

    }
    if(button == 'D'){
        player->loadImage().move(5,0);
        player->incX(5);
        player->getPos()[0] = 1;
        player->getPos()[1] = 0;
    }

    next = true;
}

bool playerWalkingState::nextPanel(){
    return next;
}
