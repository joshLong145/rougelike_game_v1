//
//  GUI.hpp
//  game_proj
//
//  Created by josh long on 2/13/17.
//  Copyright © 2017 josh long. All rights reserved.
//


/*

 
 */

#ifndef GUI_h
#define GUI_h

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include "Player.h"
class GUI{
    public:
        GUI();
        sf::Sprite displayHealthImage();
        sf::Text displayTextHealth(Player &p);
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Font font;
        sf::Text healthText;
};



#endif /* GUI_hpp */
