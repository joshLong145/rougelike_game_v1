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
        enum states {
            PlayState,
            MenuState,
            PauseState
        };
        GameState(sf::RenderWindow &w):window(w){}
        virtual ~GameState() = default;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void initilize() = 0;
        virtual bool nextPanel() = 0;
        virtual states getState() = 0;
        virtual void setNext(bool n) = 0;
        inline void init() { isInitilized = true; }
        inline bool isInit() { return isInitilized; }
        inline void setMainTimer(){ mainTimer = sf::Clock(); }
    protected:
        sf::RenderWindow &window;
        bool next = false;
        bool isInitilized = false;
        sf::Clock mainTimer;
};


#endif /* GameState_hpp */
