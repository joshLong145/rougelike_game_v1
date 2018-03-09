
#ifndef baseItem_h
#define baseItem_h

#include <SFML/Graphics.hpp>
#include <string>

class baseItem : public sf::Transformable{
public:
    //used to add items to the players active items list, abstracts the creation of objects from outside the itemManager class
    //to inside of the itemManager class.
    enum items{
        healthIncrease,
        damageIncrease,
        healthDecrease
    };

    /*
    */
    baseItem(){
      m_texture.loadFromFile("./resources/itemSheet.png");
      m_sprite.setTextureRect(sf::IntRect(50 * 8,0,50,50));
      m_sprite.setTexture(m_texture);
    }

    /*

    */
    ~baseItem() = default;

    /*
    */
    inline sf::Sprite loadImage(){ return m_sprite; }

    /*
    */
    virtual int getStatModifier() = 0;

    /*
    */
    virtual std::string getItemName() = 0;

    /*

    */
    virtual items itemType() = 0;

    /*
    */
    inline void setItemUse(bool use){ m_itemUsed = true; }

    /*
    */
    inline bool isItemUsed() { return m_itemUsed; }

    inline bool accountedFor() { return m_isAccounted; }

    inline void setAccountedFor(bool account) { m_isAccounted = account; }
protected:
    std::string m_itemName;
    int m_stateModifier;
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
    bool m_itemUsed = false;
    bool m_isAccounted = false;
};


#endif // baseItem_h
