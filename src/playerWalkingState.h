#pragma once
#ifndef playerWalkingState_h
#define playerWalkingState_h

#include "Player.h"
#include "gameObjectState.h"

class playerWalkingState : public virtual gameObjectState{
    public:
        /*
          NAME:
            playerWalkingState

          SYNOPSIS:
            playerWalkingState(const char a_direction, Player &a_player, sf::Time a_deltaTime);
                               const char a_direction -> direction the player will be moving.
                               const Player &  a_player -> reference to the player object.
                               const sf::Time a_deltaTime -> time object to sync with current frame.

          DESCRIPTION:
            Initilizes a walking state object with the desired directions, 

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        playerWalkingState(const char a_direction, Player &p, const sf::Time a_deltaTime);

        /*
          NAME:
            playerWalkingState

          SYNOPSIS:
            playerWalkingState(playerWalkingState &&other);
                               playerWalkingState &&other -> object being moved.

          DESCRIPTION:
            Move constructor for the obj.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        playerWalkingState(playerWalkingState &&other){}

        /*
          NAME:
            update

          SYNOPSIS:
            void update();

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void update();

        /*
          NAME:
            nextPanel

          SYNOPSIS:
            bool nextPanel();

          RETURNS:
            bool

          AUTHOR:
            Josh Long
        */
        bool nextPanel();
    protected:
        Player *m_player = nullptr;
        sf::Clock m_animationCLock;
        sf::Clock m_bulletCLock;
        sf::IntRect m_animationFrames;
        char button;

};

#endif
