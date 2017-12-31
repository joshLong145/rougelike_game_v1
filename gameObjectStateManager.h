

#ifndef gameObjectStateManager_h
#define gameObjectStateManager_h

#include <queue>
#include "gameObjectState.h"
#include <memory>

class gameObjectStateManager{
    public:
        gameObjectStateManager() {}
        void newPanel(gameObjectState &panel);
        void nextPanel();
        void update();
        gameObjectState & getCurrentPanel();

    private:
        std::queue<gameObjectState*> states;
};

#endif
