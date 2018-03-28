#ifndef Player_h
#define Player_h

#include "playerBullet.h"
#include "gameObjectStateManager.h"
#include "baseItem.h"
#include "bag.h"
#include <memory>

class Player : public sf::Transformable{

    public:
        // initilizes player obj
        Player(int y_pos, int x_pos);
        ~Player() = default;
        // returns a sprite obj
        sf::Sprite & loadImage();
        //player controls live here
        void playerControls(sf::Time deltaTime);
        // returns a refrence to vector of bullet obj
        std::vector<std::shared_ptr<playerBullet>> & getBulletVector();
        //called when collision is made with a wall or rock obj
        void bounce(sf::Time deltaTime);
        void bounceEnemy();
        // get health
        int getHealth();
        //set player health
        void setHealth(int h);
        //set position of the player sprite
        void setPosition(int x_val, int y_val);
        // get the position of player ( only one player obj within the game so static typing implemented to reduces object passing)
        int * getPos();

        bool isWallHit(){ return m_wallHit; }

        bool setWallHit(bool hit){ m_wallHit = hit; }

        sf::IntRect & getImageArray(int col, int row);

        void setDoor(int d);

        int getDoor();

        void clearBullets();

        void updateWalkingAnimation(char dir);
        // returns the stateManager object
        void updateStates();

        void transporForDoor();

        void addItem();

        void removeItem();

        int getOffensiveValue();

        int getDefensiveValue();

        Bag & getItemStorage();

        void addItemModifications();

        //manage color of players based on enviorment interaction
        void manageColors();

        void setDamageColorToggle(bool setting);

        void evaluateDamage(int enemyDamage);

    private:
        int velocity = 200;
        int image_row = 0;
        int image_col = 0;
        int last_move[2];
        bool m_wallHit = false;
        int health = 5;
        int door = -1;
        int attack  = 1;
        int armor = 1;
        // SFML objects
        sf::IntRect animation_frames[4][3];
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock bullet_clock;
        sf::Clock animation_clock;
        // times different colors that the player can turn;
        sf::Clock colorTiming;
        //used to time when damage can happen.
        sf::Clock m_hit_timer;
        bool damageColorToggle = false;
        // vector of bullet obj pointers
        std::vector<std::shared_ptr<playerBullet>> bullets;
        //Stores all items a player collects wihtin the game
        Bag m_playerItems;
        // object of gameObjectStateManager to manage player states
        gameObjectStateManager states;

};

#endif
