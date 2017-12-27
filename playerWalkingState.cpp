
#include "playerWalkingState.h"

playerWalkingState::playerWalkingState(char b, Player &p) : gameObjectState(){
    button = b;
    player = &p;
}

void playerWalkingState::update(){
    player->updateWalkingAnimation(button);
    sf::Vector2f pos = player->loadImage().getPosition();
    const auto speed = player->delta.asSeconds() * 100;
    if(button == 'S'){
        player->loadImage().setPosition(pos.x,pos.y +speed);
        player->incY(speed);
        player->getPos()[0] = 0;
        player->getPos()[1] = -1;

    }

    if(button == 'W'){
        player->loadImage().setPosition(pos.x,pos.y - speed);
        player->incY(-(speed));
        player->getPos()[0] = 0;
        player->getPos()[1] = 1;
    }

    if(button == 'A'){
        player->loadImage().setPosition(pos.x - speed,pos.y);
        player->incX(-(speed));
        player->getPos()[0] = -1;
        player->getPos()[1] = 0;

    }
    if(button == 'D'){
        player->loadImage().setPosition(pos.x + speed,pos.y);
        player->incX(speed);
        player->getPos()[0] = 1;
        player->getPos()[1] = 0;
    }

    next = true;
}

bool playerWalkingState::nextPanel(){
    return next;
}
