//
//  GUI.hpp
//  game_proj
//
//  Created by josh long on 2/13/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef GUI_h
#define GUI_h

#include <SFML/Graphics.hpp>
#include "Player.h"
class GUI{
    public:
        /*
          NAME:
            GUI

          SYNOPSIS:
            GUI();

          DESCRIPTION:
            Initlizes a default constructor for the class obj that takes no params.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        GUI();

        /*
          NAME:
            DisplayHealthImage

          SYNOPSIS:
            sf::Sprite DisplayHealthImage();

          DESCRIPTION:
            Returns a sprite that is repersentative of the player's health.

          RETURNS:
            sf::Sprite -> see SFML docs for more info.

          AUTHOR:
            Josh Long
        */
        sf::Sprite DisplayHealthImage();

        /*
          NAME:
            DisplayOffenseImage

          SYNOPSIS:
            sf::Sprite DisplayOffenseImage();

          DESCRIPTION:
            Returns a sprite that repersents the offensive value of the player.

          RETURNS:
            sf::Sprite -> see SFML docs for more info.

          AUTHOR:
            Josh Long
        */
        sf::Sprite DisplayOffenseImage();

        /*
          NAME:
            DisplayTextHealth

          synopsis:
            sf:;Text DisplayTextHealth(Player &p);
                                       Player &p -> refrence to player obj.
          DESCRIPTION:
            Returns a text obj with the players current health.

          RETURNS:
            sf::Text -> See SFML docs for more info.

          AUTHOR:
            Josh Long
        */
        sf::Text DisplayTextHealth(Player &a_player);

        /*
          NAME:
            DisplayTextOffense

          SYNOPSIS:
            sf:;Text DisplayTextOffense(Player &a_player);
                                        Player &a_player -> refrence to player object.

          DESCRIPTION:
            Returns a text object containing the current attack stat of the player.

          RETURNS:
            sf::Text -> see SFML docs for more info.

          AUTHOR:
            Josh Long

        */
        sf::Text DisplayTextOffense(Player &p);

        /*
          NAME:
            DisplayItems

          SYNOPSIS:
            std::vector<sf::Sprite> & DisplayItems(Player &a_player)
                                                   Player &a_player -> refrence to player object.

          DESCRIPTION:
            Returns a refrence to a vector of Sprites for each item the player has currently.

          RETURNS:
            std::vector<sf::Sprite> -> see SFML docs for more info on sf::Sprite.

          AUTHOR:
            Josh Long
        */
        std::vector<sf::Sprite> & DisplayItems(Player &p);
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
