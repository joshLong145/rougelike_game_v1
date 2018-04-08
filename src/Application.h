//
//  Application.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include "PlayState.h"
#include "MenuState.h"
#include "pauseState.h"
#include "panelManager.h"

namespace applicationManager{
   /*
    NAME:
      StartGame

    SYNOPSIS:
     void StartGame();

    DESCRIPTION:
      Main function of the game, is called within the main function and contains the main event loop and is where all checks for
      panel swithing and intilization takes place.

    RETURNS:
      void

    AUTHOR:
    Josh Long

   */
    void StartGame();

    /*
      NAME:
        AddPanel

      SYNOPSIS:
        void AddPanel(GameState::m_states state);
        GameState::m_states state -> enum signifying the type of panel being added to the queue.

      DESCRIPTION:
        Adds a new panel to the queue that will be initlized once it is active.

      RETURNS:
        void

      AUTHOR:
      Josh Long
    */
    void AddPanel(GameState::m_states state);

    /*
      NAME:
       panelManager

      SYNOPSIS:
        void AddAndSaveCurrentPanel(std::unique_ptr<GameState> a_state);
        std::unique_ptr<GameState> a_state -> state being added to the queue after panel that is
        currently active is saved.

      DESCRIPTION:
        Adds a new panel to the queue and also saves the current panel and queues it after the new
        panel is added.

      RETURNS:
        void

      AUTHOR:
        Josh Long
    */ 
    void AddAndSaveCurrentPanel(GameState::m_states state);

    /*
      NAME:
        MoveToNextPanel

      SYNOPSIS:
        void MoveToNextPanel();

      DESCRIPTION:
        Sets the plag to move to the next panel to true,
        and initlizes the next panel in the queue.

      RETURNS:
        void

      AUTHOR:
      Josh Long
    */
    void MoveToNextPanel();

    // static variables so they can only be used within the namesapce scope.
    static panelManager m_manager;
    static sf::RenderWindow m_standardWindow;
}

#endif /* Application_hpp */
