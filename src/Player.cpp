#include "Player.h"
#include "playerWalkingState.h"
#include "playerBounceState.h"
#include <memory>

// load spritesheet within the constructor of the obj
Player::Player(const int a_xPos, int a_yPos){
    // splice the sprite sheet for the player into IntRect obj (sprites are a standard 32x32)
    for(int col = 0; col < 4; col++){
        for(int row = 0; row < 3; row++){
            m_animationFrames[col][row] = sf::IntRect(row * 32,col * 32,32,32);
        }
    }
    m_texture.loadFromFile("./resources/playerSpriteSheet.png");
    //smooth sprite sheet so edges/pixels are less jaged.
    m_texture.setSmooth(true);
    // set the initial sprite to
    m_sprite.setTextureRect(m_animationFrames[3][2]);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(a_xPos,a_yPos);
}

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
    sf::Vector2f pos = m_sprite.getPosition();

    // add bullets objs to the vector if left, right, up, or down are pressed, cool down of 1 sec based on internal clock rate of one secound.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (m_bulletClock.getElapsedTime().asSeconds() > 0.5){
            m_bullets.push_back(std::make_unique<playerBullet>(pos.x + 10,pos.y,2));
            m_bulletClock.restart();
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if (m_bulletClock.getElapsedTime().asSeconds() > 0.5){
            m_bullets.push_back(std::make_unique<playerBullet>(pos.x - 10,pos.y,3));
            m_bulletClock.restart();
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if (m_bulletClock.getElapsedTime().asSeconds() > 0.5){
            m_bullets.push_back(std::make_unique<playerBullet>(pos.x,pos.y - 10,1));
            m_bulletClock.restart();
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if (m_bulletClock.getElapsedTime().asSeconds() > 0.5){
            m_bullets.push_back(std::make_unique<playerBullet>(pos.x,pos.y + 10,0));
            m_bulletClock.restart();
        }
    }

    // push a new walking state onto the event queue when a player presses a movement key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        m_states.newPanel(std::make_unique<playerWalkingState>('W', *this, deltaTime));
        // states.getCurrentPanel().setNext(true);
        return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
         m_states.newPanel(std::move(std::make_unique<playerWalkingState>('A', *this, deltaTime)));
        //states.getCurrentPanel().setNext(true);
        return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        m_states.newPanel(std::make_unique<playerWalkingState>('S', *this, deltaTime));
        //states.getCurrentPanel().setNext(true);
        return;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        m_states.newPanel(std::make_unique<playerWalkingState>('D', *this, deltaTime));
        //states.getCurrentPanel().setNext(true);
        return;
    }
   
}

void Player::EvaluateDamage(const int a_enemyDamage){
    if(m_hitTimer.getElapsedTime().asSeconds() > 1.0f){
      SetHealth(m_health - a_enemyDamage);
      SetDamageColorToggle(true);
      m_hitTimer.restart();
    }
}
// collision detection
// gets the x and y values of the obj collided with and determins where on the map it is based on pixel location
void Player::Bounce(const sf::Time a_deltaTime){
  m_states.newPanel(std::move(std::make_unique<playerBounceState>(*this, a_deltaTime)));
  m_states.getCurrentPanel().setNext(true);
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
    sf::Vector2f pos = m_sprite.getPosition();
    if(m_door == 1 || m_door == 2){
        if(m_lastMove[0] == 1 && m_lastMove[1] == 0){
          m_sprite.setPosition(pos.x - (65 * 7) - 32,pos.y);
        }
        else if (m_lastMove[0] == -1 && m_lastMove[1] == 0){
          m_sprite.setPosition(pos.x + (65 * 7) + 32,pos.y);

        }
    }else if(m_door == 3){
        m_sprite.setPosition(65 *2 - 32,300);

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
    m_states.nextPanel();
    m_states.update();
}

void Player::SetDamageColorToggle(bool setting){
    m_damageColorToggle = setting;
}

void Player::ManageColors(){
    if(m_colorTiming.getElapsedTime().asSeconds() > 1.0f){
        if(m_damageColorToggle){
            m_sprite.setColor(sf::Color::Red);
            m_damageColorToggle = !m_damageColorToggle;
        }else{
            m_sprite.setColor(sf::Color::White); //resets the sprite to the original color
        }
        m_colorTiming.restart();
    }
}

void Player::AddItemModifications(){
    for(auto item = m_playerItems.GetItems().begin(); item != m_playerItems.GetItems().end(); item++){
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
             if(m_health >= 3){
               m_health -= (*item)->GetStatModifier();
               (*item) ->SetItemUse(true);
             }else{
               m_health  = 1;
             }
           }
        }
    }
}



