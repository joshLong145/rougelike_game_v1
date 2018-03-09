#include "playerBounceState.h"

playerBounceState::playerBounceState(Player &p, const sf::Time deltaTime) : gameObjectState(){
    player = &p;
    delta = deltaTime;
}

void playerBounceState::update(){
    // calcualtes knock back distance when colliding with enemies
    const auto knock_back = delta.asSeconds() * 50;
      if((player->getPos()[0] == -1 && player->getPos()[1] == 0) ){
        player->loadImage().move(knock_back, 0);

      }else if((player->getPos()[0] == 1 && player->getPos()[1] == 0)){
        player->loadImage().move(-knock_back, 0);

      }else if( (player->getPos()[0] == 0 && player->getPos()[1] == 1) ){
        player->loadImage().move(0, knock_back);

      }else if((player->getPos()[0] == 0 && player->getPos()[1] == -1) ){
        player->loadImage().move(0,-knock_back);
      }
     next = true;
}

bool playerBounceState::nextPanel(){
    return next;
}
