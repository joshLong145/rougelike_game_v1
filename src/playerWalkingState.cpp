
#include "playerWalkingState.h"

playerWalkingState::playerWalkingState(char b, Player &p, const sf::Time deltaTime) : gameObjectState(){
    button = b;
    player = &p;
    delta = deltaTime;
}

void playerWalkingState::update(){
    player->updateWalkingAnimation(button);
    const float speed = delta.asSeconds() * 150;

    if(button == 'S'){
        player->loadImage().move(0, speed);
        player->getPos()[0] = 0;
        player->getPos()[1] = -1;
    }

    else if(button == 'W'){
        player->loadImage().move(0, -speed);
        player->getPos()[0] = 0;
        player->getPos()[1] = 1;
    }

    else if(button == 'A'){
        player->loadImage().move(-speed, 0);
        player->getPos()[0] = -1;
        player->getPos()[1] = 0;

    }
    else if(button == 'D'){
        player->loadImage().move(speed, 0);
        player->getPos()[0] = 1;
        player->getPos()[1] = 0;

    }

    next = true;
}

bool playerWalkingState::nextPanel(){
    return next;
}
