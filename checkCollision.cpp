//
//  checkCollision.cpp
//  game_proj
//
//  Created by josh long on 4/17/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#include "checkCollision.h"
namespace checkCollision{

bool checkCollisionWalls(sf::Sprite obj,std::vector<sf::Sprite> s2){
    for(unsigned int i = 0; i < s2.size(); i++){
        if(obj.getGlobalBounds().intersects(s2[i].getGlobalBounds())){
            return true;
        }
    }
    return false;
}

bool checkCollisionDoors(std::vector<std::shared_ptr<doorBlock>> door, Player &p){
    for(auto doors : door){
        if((*doors).loadImage().getGlobalBounds().intersects(p.loadImage().getGlobalBounds())){
            p.setDoor((*doors).getDirection());
            p.transporForDoor();
            return true;
        }
    }
    return false;
}

bool checkCollisionPlayerBullets(sf::Sprite obj,Player &player){
    Player *p = &player;
    std::vector<std::shared_ptr<playerBullet>> &bullets = p ->getBulletVector();
    for(auto bullet = bullets.begin(); bullet != bullets.end();bullet++){
        if(obj.getGlobalBounds().intersects((*bullet)->loadImage().getGlobalBounds())){
            bullets.erase(bullet);
            return true;
        }
    }
    return false;
}

bool checkCollisionBasic(sf::Sprite obj1,sf::Sprite obj2){
    if(obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())){
        return true;
    }else{
        return false;
    }
}

bool checkCollisionEnemies(sf::Sprite obj1, std::vector<std::unique_ptr<baseEnemy>> &enemies){
    for(auto enemy = enemies.begin(); enemy != enemies.end();enemy++){
        if(obj1.getGlobalBounds().intersects((*enemy)->loadImage().getGlobalBounds())){
            return true;
        }
    }
    return false;
}

bool checkRangeFromEnemy(sf::Sprite obj1, std::unique_ptr<baseEnemy> &enemy){
    if(enemy->path_length(obj1.getPosition().x, obj1.getPosition().y, enemy->loadImage().getPosition(). x, enemy->loadImage().getPosition().y) < 150){
        return true;
    }

    return false;
}
bool checkCollisionEnemyBullets(sf::Sprite obj,std::vector<std::unique_ptr<baseEnemy>> &enemies){

    for(auto enemy = enemies.begin(); enemy != enemies.end(); enemy++){
        std::vector<std::unique_ptr<enemyBullet>> &bullets = (*enemy)->getBulletVector();
         for(auto bullet = bullets.begin(); bullet != bullets.end();bullet++){
            if(obj.getGlobalBounds().intersects((*bullet)->loadImage().getGlobalBounds())){
                bullets.erase(bullet);
                return true;
            }
        }
    }
    return false;
}

}
