#ifndef baseBullet_h
#define baseBullet_h

#include <SFML/Graphics.hpp>

class baseBullet : public sf::Transformable{
    // public class functions
    public:
      /**
        NAME:
        baseBullet
        SYNOPSIS:
        baseBullet(const int a_xPos, const int a_yPos, const int a_dir );
        const int a_xPos -> position on the x axis for object.
        const int a_yPos -> position on the y axis for object.
        const int a_dir -> direction object will move.

        DESCRIPTION:
        Initlizes the bullet object with it's direction and x,y position.

        RETURNS:
        None

        AUTHOR:
        Josh Long
      */

      baseBullet(const int a_xPos, const int a_yPos, const int a_dir){
            m_xPos = a_xPos;
            m_yPos = a_yPos;
            // direction the bullet will be going
            m_direction = a_dir;
      }
      /**
          NAME:
            ~baseBullet
          SYNOPSIS:
            ~baseBullet() = default;

          DESCRIPTION:
            INitlizes a destructor for the bullet object.

          RETURNS:
          None

          AUTHOR:
          Josh Long
      */
      ~baseBullet() = default;

      /**
          NAME:
            LoadImage()
          SYNOPSIS:
            inline sf::Sprite LoadImage();

          DESCRIPTION:
            Returns a sprite object that can be rendered.

          RETURNS:
            sf::Sprite -> see SFML framework docs for more information.

          AUTHOR:
          Josh Long
        */
        inline sf::Sprite LoadImage(){ return m_sprite; }

        /**
          NAME:
            move
          SYNOPSIS:
            virtual void move(sf::Time a_deltaTime);
                              sf::Time a_deltaTime -> used to sync update cycle
                              with frame animation
          DESCRIPTION:
            updates bullets based on direction and velocity.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        virtual void move(sf::Time deltaTime) = 0;

 protected:
        // used to move the bullets position.
        int m_xPos;
        int m_yPos;
        // var to store direction of the bullet
        int m_direction;
        // velocity for the bullet
        const int m_velocity = 7;
        // var to store distance traveled
        int m_distance;
        // var for spritesheet
        sf::Texture m_texture;
        // sprite obj
        sf::Sprite m_sprite;
        //bool to check animation is at the end
        bool m_animation_done = false;
        //used to calculate speed
        sf::Clock m_mainTimer;
        sf::Time m_delta;
};


#endif
