#pragma once
#ifndef bulletMovingState_h
#define bulletMovingState_h

#include "baseBullet.h"
#include "gameObjectState.h"

class bulletMovingState : public virtual gameObjectState{
    public:
        bulletMovingState(int d, baseBullet &b);
        void update();
        bool nextPanel();
    protected:
        baseBullet *bullet = nullptr;
        int direction;

};

#endif
