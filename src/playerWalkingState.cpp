
#include "playerWalkingState.h"

playerWalkingState::playerWalkingState(char b, Player &p, const sf::Time deltaTime) : gameObjectState(){
    button = b;
    player = &p;
    delta = deltaTime;
}

void playerWalkingState::update(){
    player->UpdateWalkingAnimation(button);
    const float speed = delta.asSeconds() * 150;

    if(button == 'S'){
        player->LoadImage().move(0, speed);
        player->GetPos()[0] = 0;
        player->GetPos()[1] = -1;
    }

    else if(button == 'W'){
        player->LoadImage().move(0, -speed);
        player->GetPos()[0] = 0;
        player->GetPos()[1] = 1;
    }

    else if(button == 'A'){
        player->LoadImage().move(-speed, 0);
        player->GetPos()[0] = -1;
        player->GetPos()[1] = 0;

    }
    else if(button == 'D'){
        player->LoadImage().move(speed, 0);
        player->GetPos()[0] = 1;
        player->GetPos()[1] = 0;

    }

    next = true;
}

bool playerWalkingState::nextPanel(){
    return next;
}
