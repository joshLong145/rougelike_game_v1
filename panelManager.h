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

namespace Manager{

    void newPanel(std::unique_ptr<GameState> panel);
    void nextPanel();
    void update();
    void draw();
    bool switchPanel();
    GameState & getCurrentPanel();
    static std::queue<std::unique_ptr<GameState>> states;

}


#endif /* panelManger_hpp */
