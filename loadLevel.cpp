//
//  loadLevel.cpp
//  game_proj
//
//  Created by josh long on 1/31/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "loadLevel.h"
// define statements for obj being initilized within constructor
#define WALL 0
#define GROUND 1
#define NEXT_DOOR 2
#define BACK_DOOR 3

loadLevel::loadLevel(std::vector<std::string> rooms, std::vector<std::unique_ptr<baseEnemy>> &e) : enemies(std::move(e)){
    //assign enemy passed to the room to a local var
    // go through matrix and map each integer to a tile obj
    int r = 0;
    for(auto room : rooms ){
        for(int c = 0;  c < 9; c++){
            // add wall objs to both the level and rect vectors. (rect vector is for collision detection)
            if(room[c] == 'W'){
                std::shared_ptr<wallBlock> block = std::make_unique<wallBlock>(r * 65, c * 70);
                level_blocks.push_back(block);
                rects.push_back(block->loadImage());
            }
            if(room[c] == 'G'){
                level_blocks.push_back(std::make_unique<groundBlock>(r * 65, c * 70));
            }
            if(room[c] == 'N'){
                std::shared_ptr<doorBlock> door = std::make_unique<doorBlock>(r * 65, c * 70,1);
                level_blocks.push_back(door);
                doorRects.push_back(door);
                rects.push_back(door->loadImage());
            }
            if(room[c] == 'B'){
                std::shared_ptr<doorBlock> door = std::make_unique<doorBlock>(r * 65, c * 70,2);
                level_blocks.push_back(door);
                doorRects.push_back(door);
                rects.push_back(door->loadImage());
            }
        }
        r++;
    }
}

loadLevel::loadLevel(std::vector<std::string> rooms,std::vector<std::unique_ptr<baseEnemy>> &e, std::vector<std::shared_ptr<chest>> c) :
    enemies(std::move(e)),
    chests(std::move(c)){

     for(auto chest = chests.begin(); chest != chests.end(); chest++){
        rects.push_back((*chest)->loadImage());
     }
     int r = 0;
     for(auto room : rooms ){
        for(int c = 0;  c < 9; c++){
            // add wall objs to both the level and rect vectors. (rect vector is for collision detection)
            if(room[c] == 'W'){
                std::shared_ptr<wallBlock> block = std::make_unique<wallBlock>(r * 65, c * 70);
                level_blocks.push_back(block);
                rects.push_back(block->loadImage());
            }
            if(room[c] == 'G'){
                level_blocks.push_back(std::make_unique<groundBlock>(r * 65, c * 70));
            }
            if(room[c] == 'N'){
                std::shared_ptr<doorBlock> door = std::make_unique<doorBlock>(r * 65, c * 70,1);
                level_blocks.push_back(door);
                doorRects.push_back(door);
                rects.push_back(door->loadImage());
            }
            if(room[c] == 'B'){
                std::shared_ptr<doorBlock> door = std::make_unique<doorBlock>(r * 65, c * 70,2);
                level_blocks.push_back(door);
                doorRects.push_back(door);
                rects.push_back(door->loadImage());
            }
        }
        r++;
    }
}

// pass a player refrence to room obj
void loadLevel::setPlayer(Player &player){
    p = &player;
}


void loadLevel::display(sf::RenderWindow &window){
    //draw each blocks sprite
    for(auto block = level_blocks.begin(); block != level_blocks.end(); block++){
        window.draw((*block) -> loadImage() );
    }

    // draw enemies in the current room
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
        window.draw((*enemy)->loadImage() );
    }
    // draw enemies in the current room
    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
        std::vector<std::unique_ptr<enemyBullet>> &enemy_bullets = (*enemy)->getBulletVector();
        for (auto bullet = enemy_bullets.begin(); bullet != enemy_bullets.end(); bullet++){
            window.draw((*bullet)->loadImage());
        }
    }
     //draws the chests in the correct location.
    for(auto chest = chests.begin(); chest != chests.end(); chest++){
        window.draw((*chest)->loadImage());
    }

}

// returns boundiries for the level
std::vector<sf::Sprite> loadLevel::getRects(){
    return rects;
}
std::vector<std::unique_ptr<baseEnemy>> & loadLevel::getEnemies(){
    return enemies;
}

std::vector<std::shared_ptr<doorBlock>> loadLevel::getDoors(){
    return doorRects;
}

std::vector<std::shared_ptr<chest>> loadLevel::getChests(){
    return chests;
}
