//
//  PlayState.cpp
//  game_proj
//
//  Created by josh long on 5/4/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "PlayState.h"
#include <iostream>

PlayState::PlayState(sf::RenderWindow &a_windowObj):GameState(a_windowObj){}

//Initilize the all window related values for the game.
void PlayState::InitilizeGameState(){
    // resize the window and set the name of the window to game
    auto videoMode = sf::VideoMode::getDesktopMode();
    m_window.create(videoMode,"game",sf::Style::Resize);
    sf::View view;
    view.setSize(m_window.getSize().x, m_window.getSize().y);
    view.setCenter(view.getSize().x / 4, view.getSize().y / 2);
    m_window.setView(view);
    m_window.setVerticalSyncEnabled(true); // call it once, after creating the window
    m_window.setMouseCursorVisible(false);
    m_window.setFramerateLimit(60); // set the frame rate to 30 constant.
    initilizeLevels levelInit;
    // parses and loacs all level data for the game

    m_levels = levelInit.CreateAndReturnLevels();
    //set the player to the first room in the first level
    m_levels["level"+std::to_string(m_current_level)][m_current_room]->SetPlayer(m_player);
}

void PlayState::CheckRoomTransition(){
    // Checks for what door has been entered through, 
    if(m_player.GetDoor() == 1 &&
       m_levels["level" + std::to_string(m_current_level)][m_current_room]->GetEnemies().size() == 0){
        m_player.ClearBullets();
        m_current_room++;
        m_levels["level"+std::to_string(m_current_level)][m_current_room]->SetPlayer(m_player);
        m_player.SetDoor(0);

    }else if(m_player.GetDoor() == 2){
        m_player.ClearBullets();
        m_current_room--;
        m_levels["level"+std::to_string(m_current_level)][m_current_room]->SetPlayer(m_player);
        m_player.SetDoor(0);

    }else if(m_player.GetDoor() == 3){
        m_player.ClearBullets();
        m_current_level++;
        m_current_room = 0;
        m_player.SetDoor(0);
    }

}

void PlayState::UpdateGameObjects(){
    // Records time since last update cycle to sync updating with current game frame.
    // frames update at approx 60 frames second.
    sf::Time deltaTime = m_mainTimer.restart();
    //update enemy obj
    m_update_objects.UpdateEnemeyObjs(m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetEnemies(),
                                  m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetEnviormentRocks(),
                                  m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetRects(),m_player,deltaTime);

    // update all obj in level
    m_update_objects.UpdatePlayerObjs(m_player,m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetRects(),
                                   m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetEnemies(),
                                   m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetDoors(),
                                   m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetChests(),
                                   m_levels["level"+std::to_string(m_current_level)][m_current_room]->GetEnviormentRocks(),
                                   deltaTime);
}

void PlayState::update(){
  // before we check if its time to go to the next room/ level, check if the game is over aka, no more levels within the level map.
  // If that is the case then bring the player back to the menu.
  if(m_player.GetDoor() == 3 && m_current_level + 1 > m_levels.size()){
         std::cout << "g" << std::endl;
         applicationManager::AddPanel(GameState::m_states::MenuState);
         return;
    }
    //check if a door is went through by the player
    CheckRoomTransition();
    // update player, player objects, enemies, and enemy objects
    UpdateGameObjects();

    // if the player's health is 0 or less, quit the game
    if (m_player.GetHealth() <= 0){
        applicationManager::AddPanel(GameState::m_states::MenuState);
        return; // need to return from the update cycle in order to load the new state.
    }

    // if the game is paused, suspend the current state and add the save the current one.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        applicationManager::AddAndSaveCurrentPanel(GameState::m_states::PauseState);
        return;
    }

    //check for state transistions and update accordingly
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        applicationManager::AddPanel(GameState::m_states::MenuState);
        return;
    }
}

void PlayState::DrawAssets(){
    // Clear everything from the last run of the while loop
    m_window.clear();

    // display all obj within level obj
    m_levels["level"+std::to_string(m_current_level)][m_current_room]->Display(m_window);

    //display GUI elements
    m_window.draw(gui.DisplayHealthImage());

    //  draw text for the gui
    m_window.draw(gui.DisplayTextHealth(m_player));

    m_window.draw(gui.DisplayOffenseImage());

    m_window.draw(gui.DisplayTextOffense(m_player));

    //draws all item icons that the player has aquired
    gui.PositionItemTextures(m_player);
    for(auto itemSprite = m_player.GetItemStorage().GetItems().begin(); itemSprite != m_player.GetItemStorage().GetItems().end(); itemSprite++){
      m_window.draw((*itemSprite)->LoadImage());
    }
    // draw player sprite
    m_window.draw(m_player.LoadImage());

    for (auto bullet : m_player.GetBulletVector()){
        m_window.draw((*bullet).LoadImage());
    }

    // Show everything we just drew
    m_window.display();
}

GameState::m_states PlayState::GetState(){
  // Enum of the specific state is returned
  return GameState::m_states::PlayState;
}

void PlayState::SetMainClock(){
    m_mainTimer = sf::Clock();
}
