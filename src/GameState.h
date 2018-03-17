//
//  GameState.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef GameState_h
#define GameState_h
#include <SFML/Graphics.hpp>

class GameState{

    public:
        //used to keep track of which state is which for the application manager
        enum m_states {
            PlayState,
            MenuState,
            PauseState
        };
        /*
          NAME:
            GameState

          SYNOPSIS:
            GameState(sf::RenderWindow &a_windowObj)
            a_windowObj -> refrence to main render window object. gets re initlized within each game panel for custom actions.

          DESCRIPTION:
            Conctructor which takes a SFML window as input, which is iniltilzed later.
          RETURNS:
            None
          AUTHOR:
            Josh Long
        */
        GameState(sf::RenderWindow &a_windowObj):m_window(a_windowObj){}
        /*
          NAME:
            ~GameState

          SYNOPSIS:
            ~GameState() = Default

          DESCRIPTION:
            Base classes Descructor, which is initilized to false.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        virtual ~GameState() = default;
        /*
          NAME:
           update

         SYNOPSIS:
           GameState::Update();

         DESCRIPTION:
           Handles updating all assests within the current state.

         Returns:
           None

         AUTHOR:
           Josh Long
        */
        virtual void update() = 0;
        /*
          NAME:
            draw

          SYNOPSIS:
            virtual GameState::draw();

          DESCRIPTION:
            Renders all assests within the states.

          RETURNS:
            None

            AUTHOR:
              Josh Long
        */
        virtual void DrawAssets() = 0;
        /*
          NAME:
           initilize

          SYNOPSIS:
            virtual GameState::initilize(); 

          DESCRIPTION:
            Loads all dependencies and foriegn data needed for excution of the state.

          RETURNS:
            None

          AUTHOR:
           Josh Long

        */
        virtual void InitilizeGameState() = 0;
        /*
          NAME:
           nextPanel

          SYNOPSIS:
            inline GameState::nextPanel();

          DESCRIPTION:
            Checks if it is time for the next state to become active and this state either
            cached, or destoryed.

          RETURNS:
            Boolean m_next 

          AUTHOR:
            Josh Long
         */
        inline bool NextPanel(){ return m_next; }
        /*
          NAME:
           GetState

          SYNOPSIS:
            GameState::GetState();

          DESCRIPTION:
            returns a enum that correpsonds to the child state.
            TODO: Change from enum to Unique_ptr to a new instance of desired state in memory.
        */
        virtual m_states GetState() = 0;
        /*
          NAME:
           setNext

          SYNOPSIS:
           virtual GameState::setNext(bool a_isNextPanel);
           bool a_isNextPanel -> a flag that sets the m_next var to true or false.
         DESCRIPTION:
           Sets m_next to true or false which is then used to determine if it is time to go to the next state.

         RETURNS:
           None

         AUTHOR:
          Josh Long
        */
        inline void SetNextPanel(const bool a_setNext){ m_next = a_setNext; }

        /*
          NAME:
           init

          SYNOPSIS:
            inline GameState::init();

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        inline void SetToInitlized() { m_isInitilized = true; }
        /*
          NAME:
           HasBeenInitlized

          SYNOPSIS:
            virtual GameState::HasBeenInitlized();

          DESCRIPTION:
            Checks if the state has already been iniltilzed,
            if true it means that the state has already been inlized and does not need to be.
          Returns:
           boolean m_isInitilized

         AUTHOR:
           Josh Long
        */
        inline bool HasBeenInitlized() { return m_isInitilized; }
        /*
          NAME:
           setMainTimer

           SYNOPSIS:
             GameState::setMainTimer();

           DESCRIPTION:
             Reinitlizes the mainTimer within the state, which is needed to properly sync all game objects with the current frame.

           Returns:
             None

           AUTHOR:
             Josh Long
        */
        inline void SetMainTimer(){ m_mainTimer = sf::Clock(); }
    protected:
        sf::RenderWindow &m_window;
        bool m_next = false;
        bool m_isInitilized = false;
        sf::Clock m_mainTimer;
};


#endif /* GameState_hpp */
