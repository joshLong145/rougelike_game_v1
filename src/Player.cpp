#include "Player.h"
#include "playerWalkingState.h"
#include "playerBounceState.h"
#include "playerFireBulletState.h"
#include "playerBulletMultiFireState.h"
#include <memory>


#define FORWARD_DOOR 1
#define BACKWARD_DOOR 2
#define LEVEL_DOOR 3

// load spritesheet within the constructor of the obj
Player::Player(const int a_xPos, int a_yPos){
    // splice the sprite sheet for the player into IntRect obj (sprites are a standard 32x32)
    for(int col = 0; col < 4; col++){
        for(int row = 0; row < 3; row++){
            m_animationFrames[col][row] = sf::IntRect(row * 32,col * 32,32,32);
        }
    }
    // Loads sprite sheet from the Resource directory within the app route.
    m_texture.loadFromFile("./resources/playerSpriteSheet.png");
    //smooth sprite sheet so edges/pixels are less jaged.
    m_texture.setSmooth(true);
    // set the initial sprite to
    m_sprite.setTextureRect(m_animationFrames[0][1]);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(a_xPos,a_yPos);
}

//Geters and seters for all member vars within the player. Used within each player state.
sf::Sprite & Player::LoadImage(){
    return m_sprite;
}

int Player::GetHealth(){
    return m_health;
}

int * Player::GetPos(){
    return m_lastMove;
}

void Player::SetHealth(const int a_health){
    m_health = a_health;
}

void Player::SetPosition(const int a_xVal, const int a_yVal){
    m_sprite.setPosition(a_xVal,a_yVal);
}

void Player::SetDoor(const int a_door){
    m_door = a_door;
}

int Player::GetDoor(){
    return m_door;
}

void Player::PlayerControls(const sf::Time deltaTime){
    // add bullets objs to the vector if left, right, up, or down are pressed, cool down of 1 sec based on internal clock rate of one secound.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (m_bulletClock.getElapsedTime().asSeconds() > m_bulletSpeed){
          if(m_multiFire)
            m_states.NewPanel(std::make_unique<playerBulletMultiFireState>(*this,2));
          else
            m_states.NewPanel(std::make_unique<playerFireBulletState>(*this,2));

          m_bulletClock.restart();
          return;
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if (m_bulletClock.getElapsedTime().asSeconds() > m_bulletSpeed){
          if(m_multiFire)
            m_states.NewPanel(std::make_unique<playerBulletMultiFireState>(*this,3));
          else
            m_states.NewPanel(std::make_unique<playerFireBulletState>(*this,3));

          m_bulletClock.restart();
          return;
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if (m_bulletClock.getElapsedTime().asSeconds() > m_bulletSpeed){
          if(m_multiFire)
            m_states.NewPanel(std::make_unique<playerBulletMultiFireState>(*this,1));
          else
            m_states.NewPanel(std::make_unique<playerFireBulletState>(*this,1));

          m_bulletClock.restart();
          return;
       
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      if (m_bulletClock.getElapsedTime().asSeconds() >  m_bulletSpeed){
        if(m_multiFire)
          m_states.NewPanel(std::make_unique<playerBulletMultiFireState>(*this,0));
        else
          m_states.NewPanel(std::make_unique<playerFireBulletState>(*this,0));

        m_bulletClock.restart();
        return;
       
        }
    }

    // push a new walking state onto the event queue when a player presses a movement key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        m_states.NewPanel(std::make_unique<playerWalkingState>('W', *this, deltaTime));
         return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
         m_states.NewPanel(std::make_unique<playerWalkingState>('A', *this, deltaTime));
         return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        m_states.NewPanel(std::make_unique<playerWalkingState>('S', *this, deltaTime));
        //states.getCurrentPanel().setNext(true);
        return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        m_states.NewPanel(std::make_unique<playerWalkingState>('D', *this, deltaTime));
        //states.getCurrentPanel().setNext(true);
        return;
    }

}

void Player::EvaluateDamage(const int a_enemyDamage){
    // Makes sure that damage is on a delay, so that damage cannot stack rapidly.
    if(m_hitTimer.getElapsedTime().asSeconds() > 1.0f){
      SetHealth(m_health - a_enemyDamage);
      SetDamageColorToggle(true);
      // Restart so player can take damage again.
      m_hitTimer.restart();
    }
}

// collision detection
// gets the x and y values of the obj collided with and determins where on the map it is based on pixel location
void Player::Bounce(const sf::Time a_deltaTime){
  m_states.NewPanel(std::make_unique<playerBounceState>(*this, a_deltaTime));
  m_states.GetCurrentPanel().SetNext(true);
   return;
}

void Player::UpdateWalkingAnimation(char dir){
    if (m_animationClock.getElapsedTime().asSeconds() > 0.1f && dir == 'S'){
        m_imageCol = 0;
        if(m_imageRow >= 2){
            m_imageRow = 0;
            m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
        }else{
            m_imageRow++;
            m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
          }
            m_animationClock.restart();
    }else if (m_animationClock.getElapsedTime().asSeconds() > 0.1f && dir == 'W'){
            m_imageCol = 3;
            if(m_imageRow >= 2){
                m_imageRow = 0;
                m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
            }else{
                m_imageRow++;
                m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
          }

            m_animationClock.restart();
    }else if (m_animationClock.getElapsedTime().asSeconds() > 0.1f && dir == 'D'){
            m_imageCol = 2;
            if(m_imageRow >= 2){
                m_imageRow = 0;
                m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
            }else{
                m_imageRow++;
                m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
          }
            m_animationClock.restart();
    }else if (m_animationClock.getElapsedTime().asSeconds() > 0.1f && 'A'){
            m_imageCol = 1;
            if(m_imageRow >= 2){
                m_imageRow = 0;
                m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
            }else{
                m_imageRow++;
                m_sprite.setTextureRect(m_animationFrames[m_imageCol][m_imageRow]);
            }
            m_animationClock.restart();
    }
}

void Player::TransporForDoor(){
  // current position of the player.
  sf::Vector2f pos = m_sprite.getPosition();
    // if the door is one between rooms.
    if(m_door == FORWARD_DOOR || m_door == BACKWARD_DOOR){
        if(m_lastMove[0] == 1 && m_lastMove[1] == 0){
          m_sprite.setPosition(pos.x - (65 * 7) - 32,pos.y);
        }
        else if (m_lastMove[0] == -1 && m_lastMove[1] == 0){
          m_sprite.setPosition(pos.x + (65 * 7) + 32,pos.y);

        }
    }else if(m_door == LEVEL_DOOR){
        m_sprite.setPosition(65 *5 - 32,300);

    }
}

// used for damage calculation for enemies in the update cycle
int Player::GetOffensiveValue(){
    return m_attack;
}

// used for damage calculation for player in the update cycle
int Player::GetDefensiveValue(){
    return m_armor;
}
std::vector<std::shared_ptr<playerBullet>> & Player::GetBulletVector(){
    return m_bullets;
}

Bag & Player::GetItemStorage(){
    return m_playerItems;
}

void Player::ClearBullets(){
    while(m_bullets.size() > 0){
        m_bullets.pop_back();

    }
}

void Player::UpdateStates(){
    m_states.MoveToNextPanel();
    m_states.UpdatePanels();
}

void Player::SetDamageColorToggle(bool setting){
    m_damageColorToggle = setting;
}

void Player::ManageColors(){
    if(m_damageColorToggle){
            m_sprite.setColor(sf::Color::Red);
            m_damageColorToggle = !m_damageColorToggle;
            m_colorTiming.restart();
    }
    else if(m_sprite.getColor() == sf::Color::Red && m_colorTiming.getElapsedTime().asSeconds() > 2.0f){ 
            m_sprite.setColor(sf::Color::White); //resets the sprite to the original color 
            m_colorTiming.restart();
    }
}

void Player::AddItemModifications(){
    auto items =  m_playerItems.GetItems();
    for(auto item = items.begin(); item != items.end(); item++){
      
        if(!(*item)->IsItemUsed()){
            if((*item)->ItemType() == baseItem::items::healthIncrease){
                m_health += (*item)->GetStatModifier();
                (*item)->SetItemUse(true);
           }
           if((*item)->ItemType() == baseItem::items::damageIncrease){
                m_attack += (*item)->GetStatModifier();
                (*item)->SetItemUse(true);
           }
           if((*item)->ItemType() == baseItem::items::healthDecrease){
             if(m_health >= 3){ // If the users health is greater than or equal to three then we can reduce health by normal amount
               m_health -= (*item)->GetStatModifier();
               (*item)->SetItemUse(true);
             }else{
               m_health  = 1;
             }
           }
           if((*item)->ItemType() == baseItem::items::multiFire){
             if(m_multiFire && !(*item)->IsItemUsed()){
               // if the player has already gotten the multifire item, boost attack by 1
               m_attack += (*item)->GetStatModifier();
               (*item)->LoadImage().setTextureRect(sf::IntRect(50 * 4, 50 * 5,50, 50));
               (*item)->SetItemUse(true);
             }else{
               // else add multifire item.
               m_multiFire = (*item)->GetStatModifier();
               (*item)->SetItemUse(true);
             }
           }
        }
    }
}



