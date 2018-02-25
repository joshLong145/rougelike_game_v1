
#include <iostream>
#include "Update.h"
#include "checkCollision.h"

using namespace checkCollision;
// check for collisions with wall obj ( includes bullet obj from the player)
void Update::updatePlayerObjs(Player &player,std::vector<sf::Sprite> rects,std::vector<std::unique_ptr<baseEnemy>> &e,
                              std::vector<std::shared_ptr<doorBlock>> doors, std::vector<std::shared_ptr<chest>> chests,
                              std::vector<sf::Sprite> enviormentRocks,
                              sf::Time deltaTime){

    if((checkCollisionWalls(player.loadImage(),rects) || checkCollisionWalls(player.loadImage(), enviormentRocks))){
         player.bounce(deltaTime);
    }else{
        player.playerControls(deltaTime);
    }
    // checks collision with door obj if true, go to next level
    checkCollisionDoors(doors,player);

    // manages color changing based on enviorment interaction
    player.manageColors();

    // checks to see if new items where aquired by the player
    player.addItemModifications();

    // checks for collision with bullets against wall object.
    //if it does, remove it.
    std::vector<std::shared_ptr<playerBullet>> &bullets = player.getBulletVector();
    for(auto bullet = bullets.begin(); bullet != bullets.end(); ){
        if(checkCollisionWalls((*bullet) ->loadImage(),rects) || checkCollisionWalls((*bullet) ->loadImage(), enviormentRocks)){
            bullets.erase(bullet);
        }else{
            (*bullet)->move(deltaTime);
            bullet++;
        }
    }

    // check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,
    for(auto enemy = e.begin(); enemy != e.end(); enemy++){
        if(checkCollisionBasic(player.loadImage(), (*enemy) ->loadImage())){
            player.evaluateDamage((*enemy)->getDamageAmount());
        }
    }
    // check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,
    if(checkCollisionEnemyBullets(player.loadImage(),e)){
        player.evaluateDamage(1); // constant value for bullet damage ( will always be 1 unit of damage)
        hit_timer.restart();
    }

    for(auto chest = chests.begin(); chest != chests.end(); chest++){
        if(checkCollisionBasic((*chest)->loadImage(),player.loadImage())){
            if(!(*chest)->isOpened()){
                player.getItemStorage().addItem((*chest)->getItemStored());
                (*chest)->setOpened();
            }
        }
    }

    // updates player states to detmine if there is a new action ready to be performed.
    player.updateStates();
}
// checks for collision with all enemy obj
void Update::updateEnemeyObjs(std::vector<std::unique_ptr<baseEnemy>> &e,
                              std::vector<sf::Sprite> enviormentRocks,
                              std::vector<sf::Sprite> rects,
                              Player &p, sf::Time deltaTime){

    for(auto enemy = e.begin(); enemy != e.end();enemy++){
        sf::Sprite *wallObjectSprite = checkCollisionWalls((*enemy)-> loadImage(), rects);
        sf::Sprite *rockObjectSprite = checkCollisionWalls((*enemy)->loadImage(), enviormentRocks);

        if(wallObjectSprite != nullptr){
            (*enemy)->bounce(wallObjectSprite->getPosition());
        }else if(rockObjectSprite != nullptr && (*enemy)->getEnemyType() != baseEnemy::enemyType::fly){
            (*enemy)->bounce(rockObjectSprite->getPosition());
        }else{
            (*enemy)->move(p, deltaTime);
        }
    }

    for(auto enemy = e.begin(); enemy != e.end();){
        if(checkCollisionPlayerBullets((*enemy) -> loadImage(),p)){
            const int enemyHealth = (*enemy)->getHealth() - p.getOffensiveValue();
            if(enemyHealth <= 0){
                e.erase(enemy);
            }else{
                (*enemy)->setHealth(enemyHealth);
            }
        }else{
            enemy++;
        }
    }

    for(auto enemy = e.begin(); enemy!= e.end();enemy++){
        std::vector<std::unique_ptr<enemyBullet>> &bullets = (*enemy)->getBulletVector();
        for(auto bullet = bullets.begin(); bullet != bullets.end(); ){
            // checks for collision with bullets against wall object
            if(checkCollisionWalls((*bullet) ->loadImage(),rects)){
                bullets.erase(bullet);
            }else{
                (*bullet)->move(deltaTime);
                bullet++;
            }
        }
    }
}
