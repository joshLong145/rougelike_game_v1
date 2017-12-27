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
#include <memory>

PlayState::PlayState(sf::RenderWindow &w):GameState(w){
    int empty_room[10][9] = {
        {W,W,W,W,W,W,W,W,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,W,W,N,W,W,W,W,W}
    };

    int block_room[10][9] = {
        {W,W,W,B,W,W,W,W,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,G,G,G,G,G,G,G,W},
        {W,W,W,W,W,W,W,W,W}
    };

    // vector of enemies
    std::vector<std::unique_ptr<baseEnemy>> room_one_enemies;
    std::vector<std::unique_ptr<baseEnemy>> room_two_enemies;

    //vector of chests
    std::vector<std::unique_ptr<chest>> chests;
    std::unique_ptr<chest> chest_1 = std::make_unique<chest>(130,140);
    chests.push_back(std::move(chest_1));

    //enemy storage for each level
    std::unique_ptr<baseEnemy> enemy1 = std::make_unique<Ghost>(100,400,100);
    /*
    std::unique_ptr<baseEnemy> fly1 = std::make_unique<fly>(450,300,4,player);
    std::unique_ptr<baseEnemy> fly2 = std::make_unique<fly>(300,300,5,player);
    std::unique_ptr<baseEnemy> fly3 = std::make_unique<fly>(250,300,9,player);
    std::unique_ptr<baseEnemy> fly4 = std::make_unique<fly>(100,300,3,player);

    //initilize rooms with enemies
    room_one_enemies.push_back(std::move(fly1));
    room_one_enemies.push_back(std::move(fly2));
    room_one_enemies.push_back(std::move(fly3));
    room_one_enemies.push_back(std::move(fly4));
    */
    room_one_enemies.push_back(std::move(enemy1));

    //create vector that will storing view objs that load from level obj
    rooms.push_back(std::make_unique<loadLevel>(empty_room, room_one_enemies));
    rooms.push_back(std::make_unique<loadLevel>(block_room, room_two_enemies, std::move(chests)));
    rooms.at(current_room)->setPlayer(player);
}

//Initilize the all window related values for the game.
void PlayState::initilize(){
    // resize the window and set the name of the window to game
    window.create(sf::VideoMode{650, 700},"game");
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(30); // set the frame rate to 30 constant.
}
void PlayState::update(){
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

    // if the player's health is 0 or less, quit the game
    if (player.getHealth() <= 0){
        //windows closes
        window.close();
    }

    //update enemy obj
    update_objects.updateEnemeyObjs(rooms.at(current_room)->getEnemies(),rooms.at(current_room)->getRects(),player);

    // update all obj in level
    update_objects.updatePlayerObjs(player,rooms.at(current_room)->getRects(),rooms.at(current_room)->getEnemies(),rooms.at(current_room)->getDoors());

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

    // initilize the vector object with a refrence to the bullet vector in the player object.
    std::vector<std::shared_ptr<playerBullet>> &player_bullets = player.getBulletVector();
    for (auto bullet = player_bullets.begin(); bullet != player_bullets.end(); bullet++){
        window.draw((*bullet) -> loadImage() );
    }

    // draw player sprite
    window.draw(player.loadImage());

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
