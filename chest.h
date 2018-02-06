#ifndef chest_h
#define chest_h

#include <SFML/Graphics.hpp>
#include "baseItem.h"
#include <memory>

class chest {

    public:
        chest(int x, int y, std::shared_ptr<baseItem> item);

        // returns a sprite obj
        sf::Sprite loadImage();

        /*
        */
        std::shared_ptr<baseItem> getItemStored();

        bool isOpened() { return opened; }
        void setOpened() { opened = true; }
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        int x_val;
        int y_val;
        bool opened = false;
        std::shared_ptr<baseItem> m_item = nullptr;
};




#endif
