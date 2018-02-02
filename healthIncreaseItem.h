#ifndef healthIncreaseItem_h
#define healthIncreaseItem_h

#include "baseItem.h"

class healthIncreaseItem : public baseItem{
public:

    /*

    */
    healthIncreaseItem();

    /*

    */
    ~healthIncreaseItem() = default;

    /*

    */
    sf::Sprite loadImage();

    /*

    */
    int getStatModifier();

    /*

    */
    std::string getItemName();

};
#endif
