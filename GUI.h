//
//  GUI.hpp
//  game_proj
//
//  Created by josh long on 2/13/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef GUI_h
#define GUI_h

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include "Player.h"
class GUI{
    public:
        GUI();
        sf::Sprite displayHealthImage();
        sf::Sprite displayOffenseImage();
        sf::Text displayTextHealth(Player &p);
        sf::Text displayTextOffense(Player &p);
        std::vector<sf::Sprite> & displayItems(Player &p);
    private:
        sf::Texture m_healthTexture;
        sf::Texture m_offenseTexture;
        sf::Sprite m_spriteHealth;
        sf::Sprite m_spriteAttack;
        sf::Font m_font;
        sf::Text m_healthText;
        sf::Text m_offenseText;
        std::vector<sf::Sprite> m_itemSprites;
};



#endif /* GUI_hpp */
