
#ifndef baseItem_h
#define baseItem_h

#include <SFML/Graphics.hpp>
#include <string>

class baseItem{
public:
    baseItem() = default;
    ~baseItem() = default;
    virtual sf::Sprite loadImage() = 0;
    virtual int getStatModifier() = 0;
    virtual std::string getItemName() = 0;
private:
    std::string itemName;
    int stateModifier;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif // baseItem_h
