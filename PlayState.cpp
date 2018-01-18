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

//Initilize the all window related values for the game.
void PlayState::initilize(){
    // resize the window and set the name of the window to game
    window.create(sf::VideoMode{650, 700},"game");
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // set the frame rate to 30 constant.

    std::vector<std::string> levelTextFiles = {"level1.txt"};
    //Initilize all game objects
    fileReading levelFiles;
    levelFiles.openFilesForReading(levelTextFiles);
    rawGameLevels = levelFiles.readFileData();
    levelFiles.parseFileData(rawGameLevels);

    // vector of enemies
    std::vector<std::unique_ptr<baseEnemy>> room_one_enemies;
    std::vector<std::unique_ptr<baseEnemy>> room_two_enemies;

    //vector of chests
    std::vector<std::unique_ptr<chest>> chests;
    std::unique_ptr<chest> chest_1 = std::make_unique<chest>(130,140);
    chests.push_back(std::move(chest_1));

    //enemy storage for each level
    std::unique_ptr<baseEnemy> enemy1 = std::make_unique<Ghost>(100,400,100);
    std::unique_ptr<baseEnemy> fly1 = std::make_unique<fly>(200,300,4);
    std::unique_ptr<baseEnemy> fly2 = std::make_unique<fly>(300,300,5);
    std::unique_ptr<baseEnemy> fly3 = std::make_unique<fly>(250,300,9);
    std::unique_ptr<baseEnemy> fly4 = std::make_unique<fly>(100,300,9);

    //initilize rooms with enemies
    room_one_enemies.push_back(std::move(fly1));
    room_one_enemies.push_back(std::move(fly2));
    room_one_enemies.push_back(std::move(fly3));
    //second room
    room_two_enemies.push_back(std::move(fly4));
    room_two_enemies.push_back(std::move(enemy1));

    //create vector that will storing view objs that load from level obj
    rooms.push_back(std::make_unique<loadLevel>(rawGameLevels["level1"][0], room_one_enemies));
    rooms.push_back(std::make_unique<loadLevel>(rawGameLevels["level1"][1], room_two_enemies, std::move(chests)));
    rooms.push_back(std::make_unique<loadLevel>(rawGameLevels["level1"][2], room_two_enemies));
    rooms.at(current_room)->setPlayer(player);
}

void PlayState::checkRoomTransition(){
    //TODO: FIX THIS GARBAGE CODE!!!!!
    if(player.getDoor() == 1){
        player.clearBullets();
        current_room++;
        rooms.at(current_room)->setPlayer(player);
        player.setDoor(0);

    }else if(player.getDoor() == 2){
        player.clearBullets();
        current_room--;
        rooms.at(current_room)->setPlayer(player);
        player.setDoor(0);
    }

}

void PlayState::updateGameObjects(){
    sf::Time deltaTime = mainTimer.restart();
    //update enemy obj
    update_objects.updateEnemeyObjs(rooms.at(current_room)->getEnemies(),
                                    rooms.at(current_room)->getRects(),player, deltaTime);

    // update all obj in level
    update_objects.updatePlayerObjs(player,rooms.at(current_room)->getRects(),
                                    rooms.at(current_room)->getEnemies(),
                                    rooms.at(current_room)->getDoors(), deltaTime);
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
    rooms.at(current_room) -> display(window);

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
