#ifndef playerDamageState_h
#define playerDamageState_h

#include "Player.h"
#include "baseEnemy.h"
#include "gameObjectState.h"

class playerDamageState : public virtual gameObjectState{
    public:
        playerDamageState(Player &p,int damage);
        void update();
        bool nextPanel();
    private:
        Player *player = nullptr;
        int enemyDamage;
        bool next;
};

#endif
