#pragma once
#ifndef enemyWalkingState_h
#define enemyWalkingState_h

#include "baseEnemy.h"
#include "gameObjectState.h"

class enemyWalkingState : public virtual gameObjectState{
    public:
        enemyWalkingState(baseEnemy &e);
        void update();
        bool nextPanel();
    protected:
        baseEnemy *enemy = nullptr;

};

#endif
