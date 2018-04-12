#ifndef Player_h
#define Player_h

#include "playerBullet.h"
#include "gameObjectStateManager.h"
#include "baseItem.h"
#include "bag.h"
#include <memory>

class Player : public sf::Transformable{

    public:

        /**
          NAME:
            Player

          SYNOPSIS:
            Player(const int a_yPos, int a_xPos);
                   const int a_yPos -> position on the y axis for the player at initlization.
                   const int a_xPos -> position on the x axis for the player at initlization.

         DESCRIPTION:
           Initlizes a plyer object to be position at the coresponding x and y values.

         RETURNS:
           None

         AUTHOR:
           Josh Long
        */
        Player(const int a_yPos, const int a_xPos);

        /**
          NAME:
            ~Player

          SYNOPSIS:
            ~Player() = default;

         DESCRIPTION:
           Destructor, initlized to the default destructor for all custom classes.

        RETURNS:
          None

        AUTHOR:
          Josh Long
        */
        ~Player() = default;

        /**
          NAME:
            LoadImage

          SYNOPSIS:
            sf::Sprite & LoadImage();

         DESCRIPTION:
           Returns a refrence to a sprite member variable.

         RETURNS:
           sf::Sprite, see SFML documentation for info.

         AUTHOR:
           Josh Long 
        */
        sf::Sprite & LoadImage();

        /**
          NAME:
            PlayerControls

          SYNOPSIS:
            void PlayerControls(sf::Time a_deltaTime);
                                sf::Time a_deltaTime -> time passed since last update cycle.

         DESCRIPTION:
           Handles movement of the object around the game envrioment. Uses a a_deltaTime paramater to sync with the current game frame.

        RETURNS:
          None

        AUTHOR:
          Josh Long
        */
        void PlayerControls(const sf::Time a_deltaTime);

        /**
          NAME:
            GetBulletVector

          SYNOPSIS:
            std::vector<std::shared_ptr<playerBullet>> & GetBuletVector();

          DESCRIPTION:
            Returns a refrence to a vector of playerBullet objects. used to asses when game objects collide with bullet objects.

          RETURNS:
            std::vector<std::shared_ptr<playerBullet>> &

          AUTHOR:
            Josh Long
        */
        std::vector<std::shared_ptr<playerBullet>> & GetBulletVector();

        /**
          NAME:
            Bounce

          SYNOPSIS:
            void Bounce(sf::Time a_deltaTime);
                        sf::Time a_deltaTime -> time since last time update cycle.

          DESCRIPTION:
            Handles all collision with collidable envrioment objects. Used within update manager (Update.cpp).

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void Bounce(const sf::Time a_deltaTime);

        /**
          NAME:
            GetHealth

          SYNOPSIS:
            int GetHealth();

          DESCRIPTION:
            Returns the current health of the player.

          RETURNS:
            int

          AUTHOR:
            Josh Long
        */
        int GetHealth();

        /**
          NAME:
            SetHealth

          SYNOPSIS:
            SetHealth(int a_health);
                      int h -> new value of player health.

          DESCRIPTION:
            Sets the players health to a new value.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void SetHealth(const int a_health);

        /**
          NAME:
            SetPosition

          SYNOPSIS:
            SetPosition(const int a_xPos, const int a_yPos);
                        const int a_xPos -> position on the x axis
                        const int a_yPos -> position on the y axis

          DESCRIPTION:
            Sets a new positioni for the player object, used when swithcing from room to room.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void SetPosition(const int a_xVal, int a_yVal);

        /**
          NAME:
            GetPos

          SYNOPSIS:
            int * GetPos();

          DESCRIPTION:
            Returns a pointer to a 2-d vector that holds the players last successful movement.

          RETURNS:
            int *

          AUTHOR:
            Josh Long
        */
        int * GetPos();

        /**
          NAME:
            GetImageArray

          SYNOPSIS:
            GetImageArray(const int a_col, const int a_row)
                        const int a_col -> column of the matrix of the active animation frame.
                        const int a_row -> row of the matrix of the active animation frame.

          DESCRIPTION:
            Returns the current animation frame that the player is using.
            All frames of the player's animation are stored within this matrix.

          RETURNS:
           sf::IntRect & see SFML documentation for more info.

          AUTHOR:
            Josh Long
        */
        sf::IntRect & getImageArray(const int a_col, const int a_row);

        /**
          NAME:
            SetDoor

          SYNOPSIS:
            void SetDoor(int a_doorCode);
                         int a_doorCode -> the code of the corresponding door the player is interacting with.

          DESCRIPTION:
            Sets the door code of the player that has gone through.

          RETURNS:
            None

         AUTHOR:
           Josh Long
        */
        void SetDoor(const int a_door);

        /**
          NAME:
            GetDoor

          SYNOPSIS:
            GetDoor();

          DESCRIPTION:
            Returns the current door code.

          RETURNS:
            int

          AUTHOR:
            Josh Long
        */
        int GetDoor();

        /**
          NAME:
            ClearBullets

          SYNOPSIS:
            void ClearBullets

          DESCRIPTION:
            Clears the bullet within the vector.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void ClearBullets();

        /**
          NAME:
            UpdateWalkingAnimation

          SYNOPSIS:
            void UpdateWalkingAnimation(char a_dir);
                                        char a_dir -> directon player is moving in.

          DESCRIPTION:
            Abstraction used to update the moving animation based on the desired direction.

          AUTHOR:
            Josh Long
        */
        void UpdateWalkingAnimation(const char a_direction);

        /**
          NAME:
            UpdateStates

          SYNOPSIS:
            void UpdateStates();

          DESCRIPTION:
            Updates all corresponding states to the player objects,
            calls all correspoding stateManager functions.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void UpdateStates();

        /**
          NAME:
            TransportForDoor

          SYNOPSIS:
            void TransportForDoor();

          DESCTRIPTION:
            Moves the player to the next room, needs to reorintates the player to
            make sure the payer is cenetered within the room.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void TransporForDoor();

        /**
          NAME:
            AddItem

          SYNOPSIS:
            void AddItem();

          DESCRIPTION:
            Adds an Item to the players item storage.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void AddItem();

        /**
          NAME:
            GetOffensiveValue

          SYNOPSIS:
            int GetOffensiveValue();

          RETURNS:
            int

          AUTHOR:
            Josh Long
        */
        int GetOffensiveValue();

        /**
          NAME:
            GetDefensiveValue

          SYNOPSIS:
            int GetDefensiveValue();

          DESCRIPTION:
            returns the players heatlh to be evaluated externally.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        int GetDefensiveValue();

        /**
          NAME:
            GetItemStorage

          SYNOPSIS:
            Bag & GetItemStorage();

         DESCRIPTION:
           Returns a refrence to the item storage object.

         RETURNS:
           Bag &

         AUTHOR:
           Josh Long
        */
        Bag & GetItemStorage();

        /**
          NAME:
            AddItemModifications

          SYNOPSIS:
            void AddItemModifications();

          DESCRIPTION:
            Searches for a new item in the storage, if a new one has been found
            then account for its attributes in the player stats.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void AddItemModifications();

        /**
          NAME:
            ManageColors

          SYNOPSIS:
            void ManageColors();

          DESCTRIPTION:
            Handles the change of colors when damage is assigned.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void ManageColors();

        /**
          NAME:
            SetDamageColorToggle

          SYNOPSIS:
            void setDamageColorToggle(bool a_toggle);
                                      bool a_toggle -> changes the flag for color changing.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void SetDamageColorToggle(bool setting);

        /**
          NAME:
            EvaluateDamage

          SYNOPSIS:
            void EvaluateDamage(int a_enemyDamage);

          DESCRIPTION:
            Modifies the player health attributes.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void EvaluateDamage(int a_enemyDamage);

    private:
        int m_velocity = 200;

        int m_imageRow = 0;

        int m_imageCol = 0;

        int m_lastMove[2];

        bool m_wallHit = false;

        int m_health = 10;

        int m_door = -1;

        int m_attack  = 1;

        int m_armor = 1;

        float m_bulletSpeed = .5f;

        bool m_multiFire = false;

        bool m_rapidFire = false;

        // SFML objects
        sf::IntRect m_animationFrames[4][3];

        sf::Texture m_texture;

        sf::Sprite m_sprite;

        sf::Clock m_bulletClock;

        sf::Clock m_animationClock;

        // times different colors that the player can turn;
        sf::Clock m_colorTiming;

        //used to time when damage can happen.
        sf::Clock m_hitTimer;

        bool m_damageColorToggle = false;

        // vector of bullet obj pointers
        std::vector<std::shared_ptr<playerBullet>> m_bullets;

        //Stores all items a player collects wihtin the game
        Bag m_playerItems;

        // object of gameObjectStateManager to manage player states
        gameObjectStateManager m_states;

};
#endif
