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
        pauseState(sf::RenderWindow &w);
        void update();
        void initilize();
        void draw();
        bool nextPanel();
        states getState();
        void setNext(bool n);
    private:
        // for displaying text
        sf::Font font;
        sf::Text display;
        // clock for text flashing
        sf::Clock flash;
};
#endif /* MenuState_hpp */
