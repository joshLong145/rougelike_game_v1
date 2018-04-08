#pragma once
#ifndef playerRapidBulletFireState_h
#define playerRapidBulletFireState_h

#include "Player.h"
#include "gameObjectState.h"

class playerRapidBulletFireBulletState : public virtual gameObjectState{
    public:
        /*
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
        playerRapidBulletFireState(Player &p, const int a_direction);

        /*
          NAME:
            update

          SYNOPSIS:
            void update();

          DESCRIPTION:
            updates / modifies all data within the current state.
            moves player out of the colliding zone of a collidable object.

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

          DESCRIPTION:
            checks if it time to move to the next state of the players actions.

          RETURNS:
            bool

          AUTHOR:
            Josh Long
        */
        bool nextPanel();
    private:
        Player *m_player = nullptr;
        int m_direction;
};

#endif
