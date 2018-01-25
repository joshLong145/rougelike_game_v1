
#include "playerWalkingState.h"

playerWalkingState::playerWalkingState(char b, Player &p, sf::Time deltaTime) : gameObjectState(){
    button = b;
    player = &p;
    delta = deltaTime;
}

void playerWalkingState::update(){
    player->updateWalkingAnimation(button);
    sf::Vector2f pos = player->loadImage().getPosition();
    const auto speed = delta.asSeconds() * 150;
    if(button == 'S'){
        player->loadImage().setPosition(pos.x,pos.y +speed);
        player->getPos()[0] = 0;
        player->getPos()[1] = -1;

    }

    if(button == 'W'){
        player->loadImage().setPosition(pos.x,pos.y - speed);
        player->getPos()[0] = 0;
        player->getPos()[1] = 1;
    }

    if(button == 'A'){
        player->loadImage().setPosition(pos.x - speed,pos.y);
        player->getPos()[0] = -1;
        player->getPos()[1] = 0;

    }
    if(button == 'D'){
        player->loadImage().setPosition(pos.x + speed,pos.y);
        player->getPos()[0] = 1;
        player->getPos()[1] = 0;
    }

    next = true;
}

bool playerWalkingState::nextPanel(){
    return next;
}
