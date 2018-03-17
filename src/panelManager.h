//
//  panelManger.hpp
//  game_proj
//
//  Created by josh long on 5/7/17.
//  Copyright © 2017 josh long. All rights reserved.
//
/*
make this into a function maybe it will fix the mess that is this coebase
*/
#ifndef panelManger_h
#define panelManger_h

#include "GameState.h"
#include <queue>
#include <memory>

class panelManager{
public:
    /*
      NAME:
        NewPanel

      SYNOPSIS:
        panelManager::NewPanel();

      DESCRIPTION:
        Adds a new panel to the queue of game panels

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    void NewPanel(std::unique_ptr<GameState> panel);

    /*
      NAME:
        InitilizeNewPanel

      SYNOPSIS:
        void panelManager::InitlizeNewPanel();

      RETURNS:
        None

     AUTHOR:
       Josh Long
    */
    void InitilizeNewPanel();

    /*
     NAME:
        Update

     SYNOPSIS:
      void panelManager::update();

     DESCRIPTION:
       Manages all assets / sprites within the game panel and updates them every cycle ( approx 60 times a second).

     RETURNS:
       None

    AUTHOR:
      Josh Long
    */
    void Update();

    /*
      NAME:
        Draw

      SYNOPSIS:
        void paneManager:Draw();

      DESCRIPTION:
        Renders all assets / sprites within the game panel (approx 60 times a second).

     RETURNS:
       None

    AUTHOR:
      Josh Long
    */
    void draw();
    /*
      NAME:
        SwitchPanel

     SYNOPSIS:
       void panelManger SwitchPanel();

     DESCRIPTION:
       Checks if it is time to switch to the next panel, or in other words, the next state of the game.

     RETURNS:
       None

     AUTHOR:
       Josh Long
    */
    bool SwitchPanel();

    /*
      NAME:
        GetCurrentPanel

      SYNOPSIS:
        GameState & panelManager::GetCurrentPanel();

      DESCRIPTION:
        Returns a refrence to the current active panel, in other words, the one on the top of the queue.

      RETURNS:
       GameState &

      AUTHOR:
      Josh Long
    */
 
    GameState & GetCurrentPanel();

    /*
      NAME:
        RequeuePanel

      SYNOPSIS:
        void panelManager::requeuePanel();

      DESCRIPTION:
        Suspends a panel in execution and pushes it to the back of the qeueue of panels.
        The panels m_mainTimer will be reinitlized to sync with the current frame.

      RETURNS:
        None

      AUTHOR:
      Josh Long
    */
    void RequeuePanel();
private:
     std::queue<std::unique_ptr<GameState>> m_states;
};


#endif /* panelManger_hpp */
