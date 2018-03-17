//
//  MenuState.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef pauseState_h
#define pauseState_h

#include "GameState.h"

class pauseState : public virtual GameState{
    public:
        /*
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
        // ALL DOCUMENTATION FOR INHERITED FUNCTIONS WITHIN GameState BASE CLASS.
        void update();
        void InitilizeGameState();
        void DrawAssets();
        m_states GetState();
    private:
        // for displaying text
        sf::Font m_font;
        sf::Text m_display;
};
#endif /* MenuState_hpp */
