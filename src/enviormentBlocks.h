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
        /*
          NAME:
            enviormentBlocks

          SYNOPSIS:
            enviormentBlocks::MoveToNextPanel();

          DESCRIPTION:
            Initilizes a new enviorment object to be rendered in the correponding room.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        enviormentBlocks(int a_xPos, int a_yPos){
          // initlize position member variables with desired input.
          m_xPos = a_xPos;
          m_yPos = a_yPos;
          // Sets bounds on the position of the texture
          // when applied to the sprite.
          sprite.setTextureRect(sf::IntRect(0,0,65,70));
        }

        /*
          NAME:
            LoadImage

          SYNOPSIS:
            sf::Sprite LoadImage();

          Description:
            Returns the sprite corresponding to the object,
            used to render all sprites relating to the enviorment.

          RETURNS:
            Sf::Sprite 

          AUTHOR:
            Josh Long
        */
        inline sf::Sprite loadImage(){ return sprite; };

        /*
          NAME:
            SetImage

          SYNOPSIS:
            void SetImage(std::string a_imagePath);
            std::string image_path -> path to the respected image file being loaded.

          DESCRIPTION:
            loads the image that will be attached to the the texture,
            which will then be attached to the sprite.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void SetImage(std::string a_imagePath){
          texture.loadFromFile(a_imagePath);
          sprite.setTexture(texture);
          sprite.setPosition(m_xPos,m_yPos);
        }

        /*
          NAME:
           GetRect

          SYNOPSIS:
          inline sf::FloatRect GetRect();

          DESCRIPTION:
           Returns a static bounding block at the coords of the enviorment block

          RETURNS:
            sf::FLoatRect -> type created within the SFML framework.
            see SFML docs for detials.

          AUTHOR:
          Josh Long
        */
        inline sf::FloatRect GetRect(){
          return sprite.getGlobalBounds();
        }

    protected:
        int m_yPos;
        int m_xPos;
        sf::Sprite sprite;
        sf::Texture texture;

};


#endif /* enviormentBlocks_hpp */
