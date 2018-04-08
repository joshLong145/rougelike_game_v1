//
//  doorBlock.hpp
//  game_proj
//
//  Created by josh long on 5/28/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef doorBlock_h
#define doorBlock_h

#include "enviormentBlocks.h"

class doorBlock : public enviormentBlocks{
public:
    /*
      NAME:
         doorBlock

      SYNOPSIS:
        doorBlock(int a_xPos, const int a_yPos, const int a_direction);

      DESCRIPTION:
         Initlixes a doorBlock at the desired x,y positions and direction

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    doorBlock(int xpos, int ypos,int direction);

    /*
      NAME:
        draw

      SYNOPSIS:
        void draw(sf::RenderWindow &a_window);
                  sf::RenderWindow & a_window -> Reference to a window object for rendering.
                  see SFML docs for more info.

      DESCRIPTION:
        Renders all sprits wtihin the object.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    void draw(sf::RenderWindow &window);

    /*
      NAME:
        GetRect

      SYNOPSIS:
        sf::FloatRect GetRect();

      DESCRIPTION:
        Returns the bounding rectangle.

      RETURNS:
        sf::FloatRect -> see SFML docs for more info.

      AUTHOR:
        Josh Long
    */
    sf::FloatRect GetRect();

    /*
      NAME:
        getDirection

      SYNOPSIS:
        int getDirection();

      DESCRIPTION:
        Returns a integer correponding to the direction.

      RETURNS:
        int

      AUTHOR:
        Josh Long
    */
    int GetDirection();

protected:
    sf::Texture m_texture;
    int m_direction = -1;
};


#endif /* doorBlock_hpp */
