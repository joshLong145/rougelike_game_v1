#include "checkCollision.h"

namespace checkCollision{

sf::Sprite * CheckCollisionWalls(sf::Sprite a_obj,std::vector<sf::Sprite> a_s2){
    for(unsigned int i = 0; i < a_s2.size(); i++){
        if(a_obj.getGlobalBounds().intersects(a_s2[i].getGlobalBounds())){
            return &a_s2[i];
        }
    }
    return nullptr;
}

  bool CheckCollisionDoors(std::vector<std::shared_ptr<doorBlock>> a_door, Player &a_player){
    for(auto door : a_door){
        if((*door).loadImage().getGlobalBounds().intersects(a_player.loadImage().getGlobalBounds())){
            a_player.setDoor((*door).getDirection());
            a_player.transporForDoor();
            return true;
        }
    }
    return false;
}

bool CheckCollisionPlayerBullets(sf::Sprite a_obj, Player &a_player){

    std::vector<std::shared_ptr<playerBullet>> &bullets = a_player.getBulletVector();

    for(auto bullet = bullets.begin(); bullet != bullets.end();bullet++){
        if(a_obj.getGlobalBounds().intersects((*bullet)->LoadImage().getGlobalBounds())){
            bullets.erase(bullet);
            return true;
        }
    }
    return false;
}

bool CheckCollisionBasic(sf::Sprite a_obj1,sf::Sprite a_obj2){
    if(a_obj1.getGlobalBounds().intersects(a_obj2.getGlobalBounds())){
        return true;
    }else{
        return false;
    }
}

bool CheckCollisionEnemies(sf::Sprite a_obj1, std::vector<std::unique_ptr<baseEnemy>> &a_enemies){
    for(auto enemy = a_enemies.begin(); enemy != a_enemies.end();enemy++){
        if(a_obj1.getGlobalBounds().intersects((*enemy)->LoadImage().getGlobalBounds())){
            return true;
        }
    }
    return false;
}

bool CheckCollisionEnemyBullets(sf::Sprite a_obj,std::vector<std::unique_ptr<baseEnemy>> &a_enemies){

    for(auto enemy = a_enemies.begin(); enemy != a_enemies.end(); enemy++){
        std::vector<std::unique_ptr<enemyBullet>> &bullets = (*enemy)->GetBulletVector();
         for(auto bullet = bullets.begin(); bullet != bullets.end();bullet++){
            if(a_obj.getGlobalBounds().intersects((*bullet)->LoadImage().getGlobalBounds())){
                bullets.erase(bullet);
                return true;
            }
        }
    }
    return false;
}

}
