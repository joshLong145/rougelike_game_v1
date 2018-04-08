

#ifndef gameObjectStateManager_h
#define gameObjectStateManager_h

#include <queue>
#include "gameObjectState.h"
#include <memory>

class gameObjectStateManager{
    public:

        /**
          NAME:
            NewPanel

          SYNOPSIS:
            void NewPanel(std::shared_ptr<gameObjectState> a_panel);
                          std::shared_ptr<gameObjectState> a_panel -> new panel being added
                          to the queue.

          DESCRIPTION:
            Adds a new panel to the queue, once it is at the top of the queue i will be
            activated.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void NewPanel(std::shared_ptr<gameObjectState> panel);

        /**
          NAME:
            RequeuePanel

          SYNOPSIS:
            void RequeuePanel();

          DESCRIPTION:
            stores the active panel in memory then requeues it for latter reactivation.

          RETURNS:
            None

          AUTHOR:
            None
        */
        void RequeuePanel();

        /**
          NAME:
            MoveToNextPanel

          SYNOPSIS:
            void MoveToNextPanel();

          DESCRIPTION:
            pops the current panel off of the queue and initilizes the new panel.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void MoveToNextPanel();

        /**
          NAME:
            update

          SYNOPSIS:
            void UpdatePanels();

          DESCRIPTION:
            Syncronizes and updates all members within the panel.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void UpdatePanels();

        /**
          NAME:
            GetCurrentPanel

          SYNOPSIS:
            gameObjectState & GetCurrentPanel();

          DESCRIPTION:
            Returns a refrence the current panel active on the queue.

          RETURNS:
            gameObjectState & -> refrence to gameObjectState object.

          AUTHOR:
            Josh Long
        */
        gameObjectState & GetCurrentPanel();

    private:
        sf::Clock m_stateTimer;
        std::queue<std::shared_ptr<gameObjectState>> m_states;
};

#endif
