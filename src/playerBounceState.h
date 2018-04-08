#pragma once
#ifndef playerBounceState_h
#define playerBounceState_h

#include "Player.h"
#include "gameObjectState.h"

class playerBounceState : public virtual gameObjectState{
    public:
        /**
          NAME:
            playerBounceState

          SYNOPSIS:
            playerBounceState(Player &a_player, sf::Time a_deltaTime);
                              Player & a_player -> refrence to player object which is being modified.
                              sf::Time a_deltaTime -> used for keeping track of current time.

          DESCRIPTION:
            Initlizes all objects within the current object and assigns a refrence to the player.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        playerBounceState(Player &p, sf::Time deltaTime);

        /**
          NAME:
            UpdateState

          SYNOPSIS:
            void UpdateState();

          DESCRIPTION:
            updates / modifies all data within the current state.
            moves player out of the colliding zone of a collidable object.

          RETURNS:
            None

          AUTHOR:
            Josh Long
        */
        void UpdateState();

        /**
          NAME:
            nextPanel

          SYNOPSIS:
            bool nextPanel();

          DESCRIPTION:
            checks if it time to move to the next state of the players actions.

          RETURNS:
            bool

          AUTHOR:
            Josh Long
        */
        bool NextPanel();
    private:
        Player *m_player = nullptr;
        // char m_direction;
};

#endif
