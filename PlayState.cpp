//
//  PlayState.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "PlayState.h"

PlayState::PlayState(sf::RenderWindow &w):GameState(w){}

//Initilize the all window related values for the game.
void PlayState::initilize(){
    // resize the window and set the name of the window to game
    auto videoMode = sf::VideoMode::getDesktopMode();
    window.create(videoMode,"game",sf::Style::Resize);
    sf::View view;
    view.setSize(window.getSize().x, window.getSize().y);
    view.setCenter(view.getSize().x / 4, view.getSize().y / 2);
    view.zoom(1.0f);
    window.setView(view);
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60); // set the frame rate to 30 constant.
    initilizeLevels levelInit;
    // parses and loacs all level data for the game

    levels = levelInit.createAndReturnLevels();
    //set the player to the first room in the first level
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
                                   levels["level"+std::to_string(current_level)][current_room]->getDoors(),
                                   levels["level"+std::to_string(current_level)][current_room]->getChests(),
                                   deltaTime);
}

void PlayState::update(){
    // if the player's health is 0 or less, quit the game
    if (player.getHealth() <= 0){
        applicationManager::addPanel(GameState::states::MenuState);
        return; // need to return from the update cycle ( I HAVE NOT IDEA WHY THIS WORKS).
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

    window.draw(gui.displayOffenseImage());

    window.draw(gui.displayTextOffense(player));

    //draws all item icons that the player has aquired
    std::vector<sf::Sprite> itemSprites = gui.displayItems(player);
    for(auto itemSprite = itemSprites.begin(); itemSprite != itemSprites.end(); itemSprite++){
        window.draw((*itemSprite));
    }
    // draw player sprite
    window.draw(player.loadImage());

    for (auto bullet : player.getBulletVector()){
        window.draw((*bullet).loadImage());
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
