#pragma once
#ifndef playerBounceState_h
#define playerBounceState_h

#include "Player.h"
#include "gameObjectState.h"

class playerBounceState : public virtual gameObjectState{
    public:
        playerBounceState(Player &p);
        void update();
        bool nextPanel();
    private:
        Player *player = nullptr;
        char direction;
        bool next;
};

#endif
