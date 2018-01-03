//
//  panelManger.cpp
//  game_proj
//
//  Created by josh long on 5/7/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "panelManager.h"
namespace Manager{
    void newPanel(std::unique_ptr<GameState> state){
        states.push(std::move(state));
    }

    void nextPanel(){
        if(getCurrentPanel().nextPanel()){
            states.pop();
            states.front()->initilize();
        }
    }

    GameState & getCurrentPanel(){
        return *states.front();
    }

    bool switchPanel(){
        return false;
    }

    void update(){
        getCurrentPanel().update();
    }

    void draw(){
        getCurrentPanel().draw();
    }

}
