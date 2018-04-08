#ifndef pauseState_h
#define pauseState_h

#include "GameState.h"

class pauseState : public virtual GameState{
    public:
        /**
         NAME:
           pauseState

         SYNOPSIS:
           pauseState::pauseState();

         DESCRIPTION:
           Initilizes a pauseState object and initlizes all sprites / assets needed within the panel.

         RETURNS:
           None

         AUTHOR:
           Josh Long
        */
        pauseState(sf::RenderWindow &a_windowObj);

        /**
          NAME:
            update

          SYNOPSIS:
            void update();

          DESCRIPTION:
            Renders all entities within the Panel.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void update();

        /**
          NAME:
            InitilizeGameState

          SYNOPSIS:
            Initlizes all objects within the state so it is ready to be utilizes by the
            panel manager.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void InitilizeGameState();

        /**
          NAME:
            DrawAssets

          SYNOPSIS:
            void DrawAssets();

          DESCRIPTION:
            Renders all sprites within the current panel.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void DrawAssets();

        /**
          NAME:
            GetState

          SYNOPSIS:
            m_states GetState();

          DESCRIPTION:
            Returns an enum correponding to the desired state.
            in this case it is the pauseState enum type.

          RETURNS:
            m_states -> enum

          AUTHOR:
            Josh Long
        */
        m_states GetState();

 private:
        // for displaying text
        sf::Font m_font;
        sf::Text m_display;
};
#endif /* MenuState_hpp */
