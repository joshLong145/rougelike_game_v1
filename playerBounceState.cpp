#include "playerBounceState.h"

playerBounceState::playerBounceState(Player &p) : gameObjectState(){
    player = &p;
}

void playerBounceState::update(){

    if((player->getPos()[0] == -1 && player->getPos()[1] == 0) ){
        player->loadImage().move(5,0);
        player->incX(5);


    }else if((player->getPos()[0] == 1 && player->getPos()[1] == 0)){
        player->loadImage().move(-5,0);
        player->incX(-5);


    }else if( (player->getPos()[0] == 0 && player->getPos()[1] == 1) ){
        player->loadImage().move(0,5);
        player->incY(5);

    }else if((player->getPos()[0] == 0 && player->getPos()[1] == -1) ){
        player->loadImage().move(0,-5);
        player->incY(-5);

    }
    next = true;
}

bool playerBounceState::nextPanel(){
    return next;
}
