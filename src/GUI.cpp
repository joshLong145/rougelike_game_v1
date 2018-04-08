//
//  GUI.cpp
//  game_proj
//
//  Created by josh long on 2/13/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "GUI.h"
#include <string>

GUI::GUI(){
    m_healthTexture.loadFromFile("./resources/heart_icon.png");
    m_offenseTexture.loadFromFile("./resources/attack_icon.png");
    m_font.loadFromFile("./resources/sansation.ttf");
    m_spriteHealth.setTextureRect(sf::IntRect(0,0,30,35));
    m_spriteAttack.setTextureRect(sf::IntRect(0,0,32,32));
    m_spriteHealth.setTexture(m_healthTexture);
    m_spriteAttack.setTexture(m_offenseTexture);
    m_spriteHealth.setPosition(10,650);
    m_spriteAttack.setPosition(80,650);
    m_healthText.setFont(m_font);
    m_healthText.setCharacterSize(24);
    m_offenseText.setFont(m_font);
    m_offenseText.setCharacterSize(24);
    m_healthText.setPosition(50, 650);
    m_offenseText.setPosition(110, 650);
}

sf::Sprite GUI::DisplayHealthImage(){
    return m_spriteHealth;
}

sf::Sprite GUI::DisplayOffenseImage(){
    return m_spriteAttack;
}

sf::Text GUI::DisplayTextHealth(Player &a_player){
    m_healthText.setString(std::to_string(a_player.GetHealth()));
    return m_healthText;
}

sf::Text GUI::DisplayTextOffense(Player &p){
    m_offenseText.setString(std::to_string(p.GetOffensiveValue()));
    return m_offenseText;
}

std::vector<sf::Sprite> & GUI::DisplayItems(Player &p){
    for(auto item = p.GetItemStorage().GetItems().begin(); item != p.GetItemStorage().GetItems().end(); item++){
        if(!(*item)->AccountedFor()){
            m_itemSprites.push_back((*item)->LoadImage());
            (*item)->SetAccountedFor(true);
        }
    }

    int counter = 0;
    for(auto item = m_itemSprites.begin(); item != m_itemSprites.end(); item++){
        (*item).setPosition(150 + (counter * 50),650);
        counter++;
    }
    return m_itemSprites;
}
