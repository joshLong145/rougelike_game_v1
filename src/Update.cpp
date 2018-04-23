#include "Update.h"
#include "checkCollision.h"
#include "fly.h"
#include <stdlib.h>
using namespace checkCollision;

// check for collisions with wall obj ( includes bullet obj from the player)
void Update::UpdatePlayerObjs(Player &a_player,std::vector<sf::Sprite> &a_rects,std::vector<std::unique_ptr<baseEnemy>> &a_enemy,
                              std::vector<std::shared_ptr<doorBlock>> &a_doors, std::vector<std::shared_ptr<chest>> &a_chests,
                              std::vector<std::shared_ptr<rockBlock>> &a_enviormentRocks, sf::Time a_deltaTime){

   std::vector<sf::Sprite> rockSprites;
   // Go through all rocks and check if they are active.
   // If so then add them to list of colliable rocks for the player.
   for (auto rock : a_enviormentRocks){
     if(rock->IsActive())
       rockSprites.push_back(rock->LoadImage());
   }

   // Checks collision with door obj if true, go to next level
   // Check if there are no enemies in the current room before moving forward
   if(a_enemy.size() <= 0){
     CheckCollisionDoors(a_doors, a_player);
   }
   // Manages color changing based on enviorment interaction
   a_player.ManageColors();

   // Checks to see if new items where aquired by the player
   a_player.AddItemModifications();

    if((CheckCollisionWalls(a_player.LoadImage(), a_rects) || CheckCollisionWalls(a_player.LoadImage(), rockSprites))){
         a_player.Bounce(a_deltaTime);
    }else{
        a_player.PlayerControls(a_deltaTime);
    }

    // Checks for collision with bullets against wall object.
    // If it does, remove it.
    std::vector<std::shared_ptr<playerBullet>> &bullets = a_player.GetBulletVector();
    for(auto bullet = bullets.begin(); bullet != bullets.end(); ){
      if(CheckCollisionWalls((*bullet)->LoadImage(),a_rects)){
            bullets.erase(bullet);
      // Check if a bullet object collides with a rock, if so subtract fro the rocks 'health'
      }else{
        if(CheckCollisionRocks((*bullet)->LoadImage(), a_enviormentRocks)){
          bullets.erase(bullet);
        }else{
          (*bullet)->move(a_deltaTime);
          bullet++;
        }
      }
    }

    //! Check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,
    for(auto enemy = a_enemy.begin(); enemy != a_enemy.end(); enemy++){
        if(CheckCollisionBasic(a_player.LoadImage(), (*enemy)->LoadImage())){
          a_player.EvaluateDamage((*enemy)->GetDamageAmount());
        }
    }

    // Check for bullet collision with obsticals, if a bullet collides with a obstical, remove it,
    if(CheckCollisionEnemyBullets(a_player.LoadImage(),a_enemy)){
      a_player.EvaluateDamage(1); // constant value for bullet damage ( will always be 1 unit of damage)
    }

    // Loop through all chests and check if a new item is ready to be added.
    // Based on collsion with chest objects.
    for(auto chest = a_chests.begin(); chest != a_chests.end(); chest++){
        if(CheckCollisionBasic((*chest)->LoadImage(),a_player.LoadImage())){
          // Check to make sure current chast hasnt already been opened.
          if(!(*chest)->IsOpened()){
                // If not add the item to the player's item storage. 
                a_player.GetItemStorage().AddItem((*chest)->GetItemStored());
                (*chest)->SetOpened();
            }
        }
    }

    // Updates player states to detmine if there is a new action ready to be performed.
    a_player.UpdateStates();
}

// Checks for collision with all enemy obj
void Update::UpdateEnemeyObjs(std::vector<std::unique_ptr<baseEnemy>> &a_enemy,
                              std::vector<std::shared_ptr<rockBlock>> a_enviormentRocks,
                              std::vector<sf::Sprite> a_rects,
                              Player &p, sf::Time a_deltaTime){

    std::vector<sf::Sprite> rockSprites;
    for(auto rock : a_enviormentRocks){
      if(rock->IsActive())
        rockSprites.push_back(rock->LoadImage());
    }
    for(auto enemy = a_enemy.begin(); enemy != a_enemy.end(); enemy++){
        // Check for collision with all enviorment objects within a room. 
        sf::Sprite *wallObjectSprite = CheckCollisionWalls((*enemy)-> LoadImage(), a_rects);
        sf::Sprite *rockObjectSprite = CheckCollisionWalls((*enemy)->LoadImage(), rockSprites);

        // Check if a any object where returned as collided with and respond accordingly.
        if(wallObjectSprite != nullptr){
            (*enemy)->Bounce(wallObjectSprite->getPosition());
        }else if(rockObjectSprite != nullptr && (*enemy)->GetEnemyType() != baseEnemy::enemyType::fly){
            (*enemy)->Bounce(rockObjectSprite->getPosition());
        }else{
            // If no objects where collided with then the player the enemy is free to move. 
            (*enemy)->Move(p, a_deltaTime);
        }
    }

    // Check if any enemy has collided with a projectile from the player.
    // If they have then subtract the players offensive stat from the
    // enemies remaining health.
    for(auto enemy = a_enemy.begin(); enemy != a_enemy.end(); ){
        if(CheckCollisionPlayerBullets((*enemy) ->LoadImage(),p)){
            const int enemyHealth = (*enemy)->GetHealth() - p.GetOffensiveValue();
            if(enemyHealth <= 0){
              a_enemy.erase(enemy);
            }else{
                (*enemy)->SetHealth(enemyHealth);
                // If the first boss enemy takes damage, spawn flys 
                if((*enemy)->GetEnemyType() == baseEnemy::enemyType::bossOne){
                  a_enemy.push_back(std::make_unique<fly>((*enemy)->LoadImage().getPosition().x + (rand() % 50),
                                                          (*enemy)->LoadImage().getPosition().y + (rand() % 50),(rand() % 9) + 1));
                  return;
                }
            }
        }else{
            enemy++;
        }
    }

    // Check if any enemy projectiles have collided with any objects within the room.
    // If so then delete the projectile
    // if not, move the projectile.
    for(auto enemy = a_enemy.begin(); enemy!= a_enemy.end(); enemy++){
        std::vector<std::unique_ptr<enemyBullet>> &bullets = (*enemy)->GetBulletVector();
        for(auto bullet = bullets.begin(); bullet != bullets.end(); ){
            // checks for collision with bullets against wall object
            if(CheckCollisionWalls((*bullet)->LoadImage(),a_rects)){
                bullets.erase(bullet);
            }else if(CheckCollisionRocks((*bullet) ->LoadImage(), a_enviormentRocks)){
              bullets.erase(bullet);
            }else{
              (*bullet)->move(a_deltaTime);
              bullet++;
            }
       }
    }
}
