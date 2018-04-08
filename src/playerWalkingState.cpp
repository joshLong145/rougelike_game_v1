
#include "playerWalkingState.h"

playerWalkingState::playerWalkingState(char b, Player &p, const sf::Time deltaTime) : gameObjectState(){
    button = b;
    m_player = &p;
    delta = deltaTime;
}

void playerWalkingState::update(){
    m_player->UpdateWalkingAnimation(button);
    const float speed = delta.asSeconds() * 150;

    if(button == 'S'){
        m_player->LoadImage().move(0, speed);
        m_player->GetPos()[0] = 0;
        m_player->GetPos()[1] = -1;
    }

    else if(button == 'W'){
        m_player->LoadImage().move(0, -speed);
        m_player->GetPos()[0] = 0;
        m_player->GetPos()[1] = 1;
    }

    else if(button == 'A'){
        m_player->LoadImage().move(-speed, 0);
        m_player->GetPos()[0] = -1;
        m_player->GetPos()[1] = 0;

    }
    else if(button == 'D'){
        m_player->LoadImage().move(speed, 0);
        m_player->GetPos()[0] = 1;
        m_player->GetPos()[1] = 0;

    }

    next = true;
}

bool playerWalkingState::nextPanel(){
    return next;
}
