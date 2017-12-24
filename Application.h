//
//  Application.hpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include <stdio.h>
#include "PlayState.h"
#include "MenuState.h"
#include "panelManager.h"

class Application{
    public:
        Application();
        void startGame();
    private:
        PanelManager states;
        sf::RenderWindow standard_window;
};

#endif /* Application_hpp */
