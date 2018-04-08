#ifndef baseItem_h
#define baseItem_h

#include <SFML/Graphics.hpp>
#include <string>

class baseItem : public sf::Transformable{
public:
  /**
  used to add items to the players active items list, abstracts the creation of objects from outside the itemManager class inside of the itemManager class.
  */
  enum items{
        healthIncrease,
        damageIncrease,
        healthDecrease,
        multiFire
    };

    /**
      NAME:
        baseItem

      SYNOPSIS:
        baseItem::baseItem();

      DESCRIPTION:
        creates a new item object and load and map corresponding image to the texture
        for the sprite.

     RETURNS:
       None

     AUTHOR:
       Josh Long

    */
    baseItem(){
      m_texture.loadFromFile("./resources/itemSheet.png");
      m_sprite.setTexture(m_texture);
    }

    /**
      NAME:
        baseItem (destructor)

      SYNOPSIS:
        baseItem::~baseItem();

      DESCRIPTION:
        Implements a default destructor for all baseItems.

      RETURNS:
        None

     AUTHOR:
       Josh Long
    */
    ~baseItem() = default;

    /**
      NAME:
        LoadImage

      SYNOPSIS:
        inline sf::Sprite LoadImage();

      DESCRIPTION:
        Returns the sprite object used to render the item.

      RETURNS:
        sf::Sprite -> Implemented in SFML framework see docs for details

      AUTHOR:
        Josh Long
    */
    inline sf::Sprite LoadImage(){ return m_sprite; }

    /**
      NAME:
        GetStatModifier

      SYNOPSIS:
        int GetStatModifier();

      DESCRIPTION:
        returns the modifier for the stat the item is going to modifiy.

      RETURNS:
        integer

      AUTHOR:
        Josh Long
    */
    virtual int GetStatModifier() = 0;

    /**
      NAME:
        GetItemName()

      SYNOPSIS:
        virtual std::string GetItemName();

      DESCRIPTION:
        returns the name of the item

      RETURNS:
        std::string -> name of the item.

      AUTHOR:
        Josh Long
    */
    inline std::string GetItemName(){ return m_itemName; }

    /**
      NAME:
        ItemType

      SYNOPSIS:
        virtual items ItemType();

      DESCRIPTION:
        returns an itemType corresponding to the desired item.

      RETURNS:
        enum relating to the kind of item it is (defined in the child classes).

      AUTHOR:
        Josh Long
    */
    virtual items ItemType() = 0;

    /**
      NAME:
        SetItemUse

      SYNOPSIS:
        inline void SetItemUse(bool use);
        bool use -> flags the m_itemUsed var when an item is activate.

      DESCRIPTION:
        Sets m_itemUsed to true when an item is used by the player.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    inline void SetItemUse(bool use){ m_itemUsed = true; }

    /**
      NAME:
        IsItemUsed

      SYNOPSIS:
        inline bool IsItemUsed();

      DESCRIPTION:
        Returns a bool to check if an item has already been activated or not.

      RETURNS:
        boolean

      AUTHOR:
        Josh Long
    */
    inline bool IsItemUsed() { return m_itemUsed; }

    /**
      NAME;
        AccountedFor

      SYNOPSIS:
        inline bool AccountedFor();

      DESCRIPTION:
        Checks if an item has already been added to a players inventory.

      RETURNS:
        bool

      AUTHOR:
        Josh Long
    */
    inline bool AccountedFor() { return m_isAccounted; }

    /**
      NAME:
        inline void SetAccountedFor();

      SYNOPSIS:
        inline void SetAccountedFor(bool Account);
        bool Account -> sets the account.

      DESCRIPTION:
        Flag the item as accounted for so it cannot be picked up twice.

      RETURNS:
        None

      AUTHOR:
        Josh Long
    */
    inline void SetAccountedFor(bool account) { m_isAccounted = account; }

protected:
    std::string m_itemName;
    int m_statModifier = 0;
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
    bool m_itemUsed = false;
    bool m_isAccounted = false;
};


#endif // baseItem_h
