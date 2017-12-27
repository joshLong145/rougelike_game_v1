//
//  Player.h
//  game_proj
//
//  Created by josh long on 1/28/17.
//  Copyright © 2017 josh long. All rights reserved.
//
#pragma once
#ifndef Player_h
#define Player_h

#include "playerBullet.h"
#include "gameObjectStateManager.h"
#include <memory>

class Player : public sf::Transformable{

    public:
        // initilizes player obj
        Player(int y_pos, int x_pos);
        ~Player() = default;
        // returns a sprite obj
        sf::Sprite & loadImage();
        //player controls live here
        void playerControls();
        // returns a refrence to vector of bullet obj
        std::vector<std::shared_ptr<playerBullet>> & getBulletVector();
        //called when collision is made with a wall or rock obj
        void bounce();
        void bounceEnemy();
        // get health
        int getHealth();
        //set player health
        void setHealth(int h);
        //set position of the player sprite
        void setPosition(int x_val, int y_val);
        // get the position of player ( only one player obj within the game so static typing implemented to reduces object passing)
        int * getPos();
        sf::IntRect & getImageArray(int col, int row);
        void setDoor(int d);
        int getDoor();
        void clearBullets();
        void incY(int val);
        void incX(int val);
        int getY();
        int getX();
        void updateWalkingAnimation(char dir);
        // returns the stateManager object
        void updateStates();
        void transporForDoor();
        //USED IN STATES
        sf::Clock mainTimer;
        sf::Time delta; // used to calcualte player movement
    private:
        // primitive vars
        int x_val;
        int y_val;
        int velocity = 5;
        int image_row = 0;
        int image_col = 0;
        int last_move[2];
        int health = 5;
        int door = 4;
        // SFML objects
        sf::IntRect animation_frames[4][3];
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock bullet_clock;
        sf::Clock animation_clock;

        // vector of bullet obj pointers
        std::vector<std::shared_ptr<playerBullet>> bullets;
        // object of gameObjectStateManager to manage player states
        gameObjectStateManager states;
};

#endif
