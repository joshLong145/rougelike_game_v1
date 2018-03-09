

#ifndef gameObjectStateManager_h
#define gameObjectStateManager_h

#include <queue>
#include "gameObjectState.h"
#include <memory>

class gameObjectStateManager{
    public:

        gameObjectStateManager() = default;
        void newPanel(std::shared_ptr<gameObjectState> panel);
        void requeuePanel();
        void nextPanel();
        void update();
        gameObjectState & getCurrentPanel();

    private:
        sf::Clock stateTimer;
        std::queue<std::shared_ptr<gameObjectState>> states;
};

#endif
