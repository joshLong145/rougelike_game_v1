//
//  checkCollision.hpp
//  game_proj
//
//  Created by josh long on 4/17/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef checkCollision_h
#define checkCollision_h

#include <SFML/Graphics.hpp>
#include "baseEnemy.h"
#include "Player.h"
#include "doorBlock.h"
#include <memory>
namespace checkCollision{

        bool checkCollisionWalls(sf::Sprite obj,std::vector<sf::Sprite> s2);
        bool checkCollisionPlayerBullets(sf::Sprite obj,Player &p);
        bool checkCollisionBasic(sf::Sprite obj1, sf::Sprite obj2);
        bool checkCollisionEnemies(sf::Sprite obj1,std::vector<std::unique_ptr<baseEnemy>> &enemies);
        bool checkCollisionEnemyBullets(sf::Sprite obj,std::vector<std::unique_ptr<baseEnemy>> &enemies);
        bool checkRangeFromEnemy(sf::Sprite obj1, std::unique_ptr<baseEnemy> &enemy);
        bool checkCollisionDoors(std::vector<std::shared_ptr<doorBlock>> door,Player &p);
}






#endif /* checkCollision_hpp */
