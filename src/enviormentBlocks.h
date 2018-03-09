//
//  enviormentBlocks.hpp
//  game_proj
//
//  Created by josh long on 2/1/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef enviormentBlocks_h
#define enviormentBlocks_h

#include <SFML/Graphics.hpp>

/*
 base class for object inheritance, all enviorment blocks will derive from this class ( single level inheritace structure )

*/
class enviormentBlocks : public sf::Transformable{
    public:
        enviormentBlocks(int xpos, int ypos){  x_pos = xpos; y_pos = ypos;}
        virtual sf::Sprite loadImage() = 0;
        virtual void setImage(std::string image_path) = 0;
        virtual void initilizeSprite() = 0;
        virtual sf::FloatRect getRect() = 0;
    protected:
        int y_pos;
        int x_pos;
        sf::Sprite sprite;
        sf::Texture texture;

};


#endif /* enviormentBlocks_hpp */
