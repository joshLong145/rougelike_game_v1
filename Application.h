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
#include "panelManager.h"

namespace applicationManager{
    void startGame();
    void addPanel(GameState::states state);
    static panelManager manager;
    static sf::RenderWindow standard_window;
}

#endif /* Application_hpp */
