
#include <iostream>
#include "Update.h"
#include "checkCollision.h"

using namespace checkCollision;
// check for collisions with wall obj ( includes bullet obj from the player)
void Update::updatePlayerObjs(Player &player,std::vector<sf::Sprite> rects,std::vector<std::unique_ptr<baseEnemy>> &e,
                              std::vector<std::shared_ptr<doorBlock>> doors,sf::Time deltaTime){

    std::vector<std::shared_ptr<playerBullet>> &bullets = player.getBulletVector();
    if(checkCollisionWalls(player.loadImage(),rects) ){
        player.bounce(deltaTime);
    }else{
        player.playerControls(deltaTime);
    }
    // checks collision with door obj if true, go to next level
    checkCollisionDoors(doors,player);
    // manages color changing based on enviorment interaction
    player.manageColors();
    // checks for collision with bullets against wall object.
    //if it does, remove it.
    for(auto bullet = bullets.begin(); bullet != bullets.end();){
        if(checkCollisionWalls((*bullet) ->loadImage(),rects)){
            bullets.erase(bullet);
        }else{
            (*bullet)->move();
            bullet++;
        }
    }
    // check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,
    for(auto enemy = e.begin(); enemy != e.end(); enemy++){
        if(checkCollisionBasic(player.loadImage(), (*enemy) ->loadImage())){
            if(hit_timer.getElapsedTime().asSeconds() > 1.0f){
                player.setHealth((player.getHealth() - 1));
                player.setDamageColorToggle(true);
                hit_timer.restart();
            }
            (*enemy)->hitNonWallObj();
        }
    }
    // check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,

    if(checkCollisionEnemyBullets(player.loadImage(),e)){
        if(hit_timer.getElapsedTime().asSeconds() > 1.0f){
                player.setHealth((player.getHealth() - 1));
                player.setDamageColorToggle(true);
                hit_timer.restart();
        }
    }
    // updates player states to detmine if there is a new action ready to be performed.
    player.updateStates();
}
// checks for collision with all enemy obj
void Update::updateEnemeyObjs(std::vector<std::unique_ptr<baseEnemy>> &e, std::vector<sf::Sprite> rects,
                              Player &p, sf::Time deltaTime){
    for(auto enemy = e.begin(); enemy != e.end();enemy++){
        sf::Sprite *wallObjectSprite = checkCollisionWalls((*enemy)-> loadImage(),rects);
        if(wallObjectSprite != nullptr){
            (*enemy)->bounce(wallObjectSprite->getPosition());
        }else{
            (*enemy)->move(p, deltaTime);
        }
    }

    for(auto enemy = e.begin(); enemy != e.end();){
        if(checkCollisionPlayerBullets((*enemy) -> loadImage(),p)){
            if(((*enemy)->getHealth() <= 0)){
                e.erase(enemy);
            }else{
                (*enemy)->setHealth((*enemy)->getHealth() - p.getOffensiveValue()); //TODO::
            }
        }else{
            enemy++;
        }
    }
    for(auto enemy = e.begin(); enemy != e.end(); enemy++){
        if(checkRangeFromEnemy(p.loadImage(),*enemy)){
            (*enemy)->setBulletDirection();
        }
    }
    for(auto enemy = e.begin(); enemy!= e.end();enemy++){
            std::vector<std::unique_ptr<enemyBullet>> &bullets = (*enemy)->getBulletVector();
            for(auto bullet = bullets.begin(); bullet != bullets.end();){
                // checks for collision with bullets against wall object
                if(checkCollisionWalls((*bullet) ->loadImage(),rects)){
                    bullets.erase(bullet);
                }else{
                    (*bullet)->move();
                    bullet++;
                }
        }

    }
}
