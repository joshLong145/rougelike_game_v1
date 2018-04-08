
#ifndef rockBlocks_h
#define rockBlocks_h

#include "enviormentBlocks.h"

class rockBlock : public enviormentBlocks{
public:

    /**
      NAME:
        rockBlock

      SYNOPSIS:
        rockBlock::rockBlock(int xpos, int ypos);
        xpos -> x position of the envriomentBlock
        ypos -> y position of the envriormentBlock

      DESCRIPTION:
        Initlizes a rock to be loaded into a room.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    rockBlock(int xpos, int ypos);

    /**
      NAME:
        GetHealth

      SYNOPSIS:
       int GetHealth();

     DESCRIPTION:
       Returns the current health of the rock object.

     RETURNS:
       int

     AUTHOR:
       Josh Long
    */
    int GetHealth(){ return m_health; }

    /**
      NAME:
        SetHealth

      SYNOPSIS:
        void SetHealth(const int a_newHealth);
                       const int a_newHealth -> new value for rock object's health.

      DESCRIPTION:
        Sets the rock object health to a new value.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    void SetHealth(const int a_newHealth){ m_health = a_newHealth; }

    /**
      NAME:
        IsActive

      SYNOPSIS:
        bool isActive();

      DESCRIPTION:
        Checks if the rock is active (i.e. is it still a rock)

      RETURNS:
        bool

      AUTHOR:
        Josh Long
    */
    bool IsActive(){return m_active; }

    /**
      NAME:
        SetActive

      SYNOPSIS:
        void setActive(bool a_active);
        bool a_active -> toggle for rock.

     DESCRIPTION:
       Sets the rock active or inactive.

     RETURNS:
       None

     AUTHOR:
       Josh Long
    */
    void SetActive(bool a_active){m_active = a_active;}

    /**
      NAME:
        SetGroundTexture

      SYNOPSIS:
        void setGroundTexture();

      DESCRIPTION:
        set the ground texture as new texture for the rock after it has been destroyed.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    void SetGroundTexture(){ m_sprite.setTexture(m_groundBlockTexture); }

private:
    int m_health = 3;
    bool m_active = true;
    sf::Texture m_groundBlockTexture;
};

#endif
