//
//  Update.hpp
//  game_proj
//
//  Created by josh long on 4/6/17.
//  Copyright © 2017 josh long. All rights reserved.
//

#ifndef Update_h
#define Update_h

#include "Player.h"
#include "baseEnemy.h"
#include "doorBlock.h"
#include <memory>
class Update{
    public:
        Update(){};
        void updatePlayerObjs(Player &p,std::vector<sf::Sprite> rects,std::vector<std::unique_ptr<baseEnemy>> &e,
                              std::vector<std::shared_ptr<doorBlock>> doorRects, sf::Time deltaTime);

        void updateEnemeyObjs(std::vector<std::unique_ptr<baseEnemy>> &e,
                              std::vector<sf::Sprite> rects, Player &p, sf::Time deltaTime);
    private:
        sf::Clock hit_timer;
};

#endif /* Update_hpp */
