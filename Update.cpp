
#include <iostream>
#include "Update.h"
#include "checkCollision.h"
// obj for collision detection
checkCollision collide;
// check for collisions with wall obj ( includes bullet obj from the player)
void Update::updatePlayerObjs(Player &player,std::vector<sf::Sprite> rects,std::vector<std::unique_ptr<baseEnemy>> &e,std::vector<doorBlock*> doors){

    std::vector<std::shared_ptr<playerBullet>> &bullets = player.getBulletVector();
    if(collide.checkCollisionWalls(player.loadImage(),rects) ){
        player.bounce();
    }else{
        player.playerControls();
    }
    // checks collision with door obj if true, go to next level
    collide.checkCollisionDoors(doors,player);
    // checks for collision with bullets against wall object
    for(auto bullet = bullets.begin(); bullet != bullets.end();){
        if(collide.checkCollisionWalls((*bullet) ->loadImage(),rects)){
            bullets.erase(bullet);
        }else{
            (*bullet)->move();
            bullet++;
        }
    }
    // check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,
    for(auto enemy = e.begin(); enemy != e.end();enemy++){
        if(collide.checkCollisionBasic(player.loadImage(), (*enemy) ->loadImage())){
            if(hit_timer.getElapsedTime().asSeconds() > 1.0f){
                player.setHealth((player.getHealth() - 1));
                hit_timer.restart();
            }
            (*enemy)->hitNonWallObj();
        }
    }
    // check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,

    if(collide.checkCollisionEnemyBullets(player.loadImage(),e)){
        if(hit_timer.getElapsedTime().asSeconds() > 1.0f){
                player.setHealth((player.getHealth() - 1));
                hit_timer.restart();
        }
    }

    player.updateStates();
}
// checks for collision with all enemy obj
void Update::updateEnemeyObjs(std::vector<std::unique_ptr<baseEnemy>> &e,std::vector<sf::Sprite> rects,Player &p){
    for(auto enemy = e.begin(); enemy != e.end();){
        if(collide.checkCollisionWalls((*enemy)-> loadImage(),rects)){
            (*enemy)->bounce();
            enemy++;
        }else{
            (*enemy)->move(p);
            enemy++;
        }
    }

    for(auto enemy = e.begin(); enemy != e.end();){
        if(collide.checkCollisionPlayerBullets((*enemy) -> loadImage(),p)){
            e.erase(enemy);
        }else{
            enemy++;
        }
    }
    for(auto enemy = e.begin(); enemy != e.end(); enemy++){
        if(collide.checkRangeFromEnemy(p.loadImage(),*enemy)){
            (*enemy)->setBulletDirection();
        }
    }
    for(auto enemy = e.begin(); enemy!= e.end();enemy++){
            std::vector<std::unique_ptr<enemyBullet>> &bullets = (*enemy)->getBulletVector();
            for(auto bullet = bullets.begin(); bullet != bullets.end();){
                // checks for collision with bullets against wall object
                if(collide.checkCollisionWalls((*bullet) ->loadImage(),rects)){
                    bullets.erase(bullet);
                }else{
                    (*bullet)->move();
                    bullet++;
                }
        }

    }
}
