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
    texture.loadFromFile("heart_icon.png");
    font.loadFromFile("sansation.ttf");
    sprite.setTextureRect(sf::IntRect(0,0,30,35));
    sprite.setTexture(texture);
    sprite.setPosition(10,650);
    healthText.setFont(font);
    healthText.setCharacterSize(24);
    healthText.setPosition(50,650);
}

sf::Sprite GUI::displayHealthImage(){
    return sprite;
}

sf::Text GUI::displayTextHealth(Player &p){
    healthText.setString(std::to_string(p.getHealth()));
    return healthText;
}

std::vector<sf::Sprite> & GUI::displayItems(Player &p){
    for(auto item = p.getItemStorage().getItems().begin(); item != p.getItemStorage().getItems().end(); item++){
        m_itemSprites.push_back((*item)->loadImage());
    }
    for( auto item : m_itemSprites){
        item.setPosition(50,650);
    }
    return m_itemSprites;
}
