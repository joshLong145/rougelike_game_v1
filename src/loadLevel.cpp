//
//  loadLevel.cpp
//  game_proj
//
//  Created by josh long on 1/31/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "loadLevel.h"

loadLevel::loadLevel(std::vector<std::string> rooms, std::vector<std::unique_ptr<baseEnemy>> &e) : m_enemies(std::move(e)){
    //assign enemy passed to the room to a local var
    // go through matrix and map each integer to a tile obj
    int r = 0;
    for(auto room : rooms ){
      for(unsigned int c = 0;  c < room.size(); c++){
            // add wall objs to both the level and rect vectors. (rect vector is for collision detection)
            if(room[c] == 'W'){
                std::shared_ptr<wallBlock> block = std::make_unique<wallBlock>(r * 65, c * 70);
                m_levelBlocks.push_back(block);
                m_rects.push_back(block->loadImage());
            }
            if(room[c] == 'G'){
                m_levelBlocks.push_back(std::make_unique<groundBlock>(r * 65, c * 70));
            }
            if(room[c] == 'N'){
                std::shared_ptr<doorBlock> door = std::make_unique<doorBlock>(r * 65, c * 70,1);
                m_levelBlocks.push_back(door);
                m_doorRects.push_back(door);
                m_rects.push_back(door->loadImage());
            }
            if(room[c] == 'B'){
                std::shared_ptr<doorBlock> door = std::make_unique<doorBlock>(r * 65, c * 70,2);
                m_levelBlocks.push_back(door);
                m_doorRects.push_back(door);
                m_rects.push_back(door->loadImage());
            }
            if(room[c] == 'R'){
                std::shared_ptr<rockBlock> rock = std::make_unique<rockBlock>(r * 65, c * 70);
                m_levelBlocks.push_back(rock);
                m_rockRects.push_back(rock->loadImage());
            }
            if(room[c] == 'C'){
                std::shared_ptr<chest> chestTile = std::make_unique<chest>(r * 65,c * 70);
                m_levelBlocks.push_back(chestTile);
                m_chests.push_back(chestTile);
                m_rockRects.push_back(chestTile->loadImage());
            }
            if(room[c] == 'L'){
                std::shared_ptr<levelDoorBlock> door = std::make_unique<levelDoorBlock>(r * 65, c * 70,3);
                m_levelBlocks.push_back(door);
                m_doorRects.push_back(door);
                m_rects.push_back(door->loadImage());
            }
        }
        r++;
    }
}

// pass a player refrence to room obj
void loadLevel::SetPlayer(Player &a_player){
  // Initlizes the player var from being nullptr to a refrence to the player object.
  //there is only one player object so it needs to be passed by refrence from object to object. This is done to prevent memory leakage and decrease memory footprint.
  m_player = &a_player;
}


void loadLevel::Display(sf::RenderWindow &a_windowObj){
    //draw each blocks sprite
    for(auto block = m_levelBlocks.begin(); block != m_levelBlocks.end(); block++){
        a_windowObj.draw((*block) -> loadImage() );
    }

    // draw enemies in the current room
    for (auto enemy = m_enemies.begin(); enemy != m_enemies.end(); enemy++){
        a_windowObj.draw((*enemy)->LoadImage() );
    }
    // draw enemies in the current room
    for (auto enemy = m_enemies.begin(); enemy != m_enemies.end(); enemy++){
        std::vector<std::unique_ptr<enemyBullet>> &enemyBullets = (*enemy)->GetBulletVector();
        for (auto bullet = enemyBullets.begin(); bullet != enemyBullets.end(); bullet++){
            a_windowObj.draw((*bullet)->LoadImage());
        }
    }
}

// returns boundiries for the level
std::vector<sf::Sprite> & loadLevel::GetRects(){
    return m_rects;
}

std::vector<sf::Sprite> & loadLevel::GetEnviormentRocks(){
    return m_rockRects;
}

std::vector<std::unique_ptr<baseEnemy>> & loadLevel::GetEnemies(){
    return m_enemies;
}

std::vector<std::shared_ptr<doorBlock>> & loadLevel::GetDoors(){
    return m_doorRects;
}

std::vector<std::shared_ptr<chest>> & loadLevel::GetChests(){
    return m_chests;
}
