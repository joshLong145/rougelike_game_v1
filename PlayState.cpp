//
//  PlayState.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "PlayState.h"
#include "Ghost.h"
#include "fly.h"
#include "chest.h"
#include "panelManager.h"
#include "MenuState.h"
#include <memory>

using namespace Manager;

PlayState::PlayState(sf::RenderWindow &w):GameState(w){}

std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> PlayState::initlizeLevels(){
    std::map<std::string,std::vector<std::unique_ptr<loadLevel>>> levelData;

    std::vector<std::string> levelTextFiles = {"level1.txt"};
    std::vector<std::string> EnemyTextFiles = {"enemiesLevel1.txt"};

    //Initilize all game objects
    envriormentReading levelFiles;
    enemyReading enemyFiles;
    levelFiles.openFilesForReading(levelTextFiles);
    rawGameLevels = levelFiles.readFileData();
    levelFiles.parseFileData(rawGameLevels);
    enemyFiles.openFilesForReading(EnemyTextFiles);
    rawEnemies = enemyFiles.readFileData();

    //create enmies from raw enemy data
    std::map<std::string,std::map<std::string,std::vector<std::unique_ptr<baseEnemy>>>> enemyData;
    //cycle through all rawEnemy data and parse into game objects
    for(auto enemy : rawEnemies){
        std::string enemyType = std::get<1>(enemy.second);
        std::string room = std::get<0>(enemy.second);
        int xValue = std::get<2>(enemy.second);
        int yValue = std::get<3>(enemy.second);
        int velocity = std::get<4>(enemy.second);

        //depending on the enemy create a ptr obj of it and put it into its corresponding room.
        if(enemyType == "fly"){
            enemyData[enemy.first][room].push_back(std::make_unique<fly>(xValue, yValue, velocity));
        }
        if(enemyType == "ghost"){
            enemyData[enemy.first][room].push_back(std::make_unique<Ghost>(xValue, yValue, velocity));
        }
    }

    for(auto level : rawGameLevels){
        int roomNumber = 1;
        for(unsigned int i = 0; i < level.second.size(); i++){
            levelData[level.first].push_back(std::make_unique<loadLevel>(rawGameLevels[level.first][i],
                                                                         enemyData[level.first]["room"+std::to_string(roomNumber)]));
            roomNumber++;
        }
    }

    return levelData;
}


//Initilize the all window related values for the game.
void PlayState::initilize(){
    // resize the window and set the name of the window to game
    window.create(sf::VideoMode{650, 700},"game");
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // set the frame rate to 30 constant.

    levels = initlizeLevels();

    levels["level"+std::to_string(current_level)][current_room]->setPlayer(player);
}

void PlayState::checkRoomTransition(){
    //TODO: FIX THIS GARBAGE CODE!!!!!
    if(player.getDoor() == 1){
        player.clearBullets();
        current_room++;
        //rooms.at(current_room)->setPlayer(player);
        player.setDoor(0);

    }else if(player.getDoor() == 2){
        player.clearBullets();
        current_room--;
        //rooms.at(current_room)->setPlayer(player);
        player.setDoor(0);
    }

}

void PlayState::updateGameObjects(){
    sf::Time deltaTime = mainTimer.restart();
    //update enemy obj
    update_objects.updateEnemeyObjs(levels["level"+std::to_string(current_level)][current_room]->getEnemies(),
                                  levels["level"+std::to_string(current_level)][current_room]->getRects(),player, deltaTime);

    // update all obj in level
    update_objects.updatePlayerObjs(player,levels["level"+std::to_string(current_level)][current_room]->getRects(),
                                   levels["level"+std::to_string(current_level)][current_room]->getEnemies(),
                                   levels["level"+std::to_string(current_level)][current_room]->getDoors(), deltaTime);
}

void PlayState::update(){
    // if the player's health is 0 or less, quit the game
    if (player.getHealth() <= 0){
        //windows closes
        window.close();
    }
    //check if a door is went through by the player
    checkRoomTransition();
    // update player, player objects, enemies, and enemy objects
    updateGameObjects();
}

void PlayState::draw(){
    // Clear everything from the last run of the while loop
    window.clear();

    // display all obj within level obj
    levels["level"+std::to_string(current_level)][current_room]->display(window);

    //display GUI elements
    window.draw(gui.displayHealthImage());

    //  draw text for the gui
    window.draw(gui.displayTextHealth(player));

    // draw player sprite
    window.draw(player.loadImage());

    for (auto bullet : player.getBulletVector()){
        window.draw((*bullet).loadImage() );
    }

    // Show everything we just drew
    window.display();
}

bool PlayState::nextPanel(){
    return next;
}

void PlayState::setNext(bool n){
    next = n;
}

GameState::states PlayState::getState(){
    return GameState::states::PlayState;
}
