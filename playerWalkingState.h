#pragma once
#ifndef playerWalkingState_h
#define playerWalkingState_h

#include "Player.h"
#include "gameObjectState.h"

class playerWalkingState : public virtual gameObjectState{
    public:
        playerWalkingState(char d, Player &p, sf::Time deltaTime);
        void update();
        bool nextPanel();
    protected:
        Player *player = nullptr;
        sf::Clock animationCLock;
        sf::Clock bulletCLock;
        sf::IntRect animationFrames;
        char button;

};

#endif
