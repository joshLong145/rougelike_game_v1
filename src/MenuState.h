//
//  MenuState.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef MenuState_h
#define MenuState_h

#include "GameState.h"

class MenuState : public virtual GameState{
    public:
        /*
         NAME:
           MenuState

         SYNOPSIS:
           MenuState::MenuState(sf::RenderWindow &a_windowObj);
           a_windowObj -> a RenderWindow object passed by refrence from the applicationManager
           that is inilized to the current states specifications.

         DESCRIPTION:
           Iniltizes a MenuState object and initlizes all textures / assets needed for the panel.

         RETURNS:
           None

         AUTHOR:
           Josh Long
        */
        MenuState(sf::RenderWindow &a_windowObj);
        // DOCUMENTATION FOR INHERITED FUNCTIONS FOUND IN GameState BASE CLASS.
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
