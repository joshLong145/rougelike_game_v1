
#ifndef baseItem_h
#define baseItem_h

#include <SFML/Graphics.hpp>
#include <string>

class baseItem{
public:
    //used to add items to the players active items list, abstracts the creation of objects from outside the itemManager class
    //to inside of the itemManager class.
    enum items{
        healthIncrease,
        damageIncrease
    };
    /*
    */
    baseItem() = default;
    /*

    */
    ~baseItem() = default;
    /*
    */
    virtual sf::Sprite loadImage() = 0;
    /*
    */
    virtual int getStatModifier() = 0;
    /*
    */
    virtual std::string getItemName() = 0;

protected:
    std::string m_itemName;
    int m_stateModifier;
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
};


#endif // baseItem_h
