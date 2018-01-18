#include "playerBounceState.h"

playerBounceState::playerBounceState(Player &p, sf::Time deltaTime) : gameObjectState(){
    player = &p;
    delta = deltaTime;
}

void playerBounceState::update(){
    const auto pos = player->loadImage().getPosition();
    // calcualtes knock back distance when colliding with enemies
    const auto knock_back = delta.asSeconds() * 80;

    if((player->getPos()[0] == -1 && player->getPos()[1] == 0) ){
        player->loadImage().setPosition(pos.x + knock_back, pos.y);

    }else if((player->getPos()[0] == 1 && player->getPos()[1] == 0)){
        player->loadImage().setPosition(pos.x - knock_back, pos.y);

    }else if( (player->getPos()[0] == 0 && player->getPos()[1] == 1) ){
        player->loadImage().setPosition(pos.x, pos.y + knock_back);

    }else if((player->getPos()[0] == 0 && player->getPos()[1] == -1) ){
        player->loadImage().setPosition(pos.x, pos.y - knock_back);
    }
    next = true;
}

bool playerBounceState::nextPanel(){
    return next;
}
