//
//  loadLevel.hpp
//  game_proj
//
//  Created by josh long on 1/31/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef loadLevel_h
#define loadLevel_h

#include "Player.h"
#include "baseEnemy.h"
#include "groundBlock.h"
#include "wallBlock.h"
#include "doorBlock.h"
#include "chest.h"
#include <memory>

/*
renders each room of the game. all textures that could potentially be used are rendered during obj initialization.
player object is passed by refrence to the object.
display() and update() update any object on the screen and display will display any objects to the window which is passed by refrence to display().
*/

class loadLevel{
    public:
        loadLevel(int map[10][9],std::vector<std::unique_ptr<baseEnemy>> &e);
        loadLevel(int map[10][9],std::vector<std::unique_ptr<baseEnemy>> &e,std::vector<std::unique_ptr<chest>> chests);
        void setPlayer(Player &player);
        void display(sf::RenderWindow &window);
        void update();
        std::vector<sf::Sprite> getRects();
        std::vector<std::unique_ptr<baseEnemy>> & getEnemies();
        std::vector<doorBlock*> getDoors();
    private:
        Player *p = nullptr;
        //stores enviorment blocks for the room
        std::vector<enviormentBlocks*> level_blocks;
        std::vector<sf::Sprite> rects;
        //container for handling door collisions
        std::vector<doorBlock*> doorRects;
        //stores enemies for the given room
        std::vector<std::unique_ptr<baseEnemy>> enemies;
        // stores chests that are within the room
        std::vector<std::unique_ptr<chest>> chests = {};
};

#endif /* loadLevel_hpp */
