#pragma once
#ifndef playerFireBulletState_h
#define playerFireBullet_h

#include "Player.h"
#include "gameObjectState.h"

class playerBulletMultiFireState : public virtual gameObjectState{
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
        playerBulletMultiFireState(Player &p, const int a_direction);

        /**
           NAME:
             playerBulletMultiFire

           SYNOPSIS:
             ~playerBulletMultiFire() = default;

           DESCRIPTION:
             Default destructor for all playerBulletMultiFire.

           RETURNS:
             None

           AUTHOR:
             Josh Long
        */
        ~playerBulletMultiFireState() = default;

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
            NextPanel

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
        int m_direction;
};

#endif
