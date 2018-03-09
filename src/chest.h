#ifndef chest_h
#define chest_h

#include <SFML/Graphics.hpp>
#include "baseItem.h"
#include "enviormentBlocks.h"
#include "healthIncreaseItem.h"
#include "damageIncreaseItem.h"
#include "healthDecreaseItem.h"
#include <memory>

class chest : public enviormentBlocks {

    public:
        chest(int x, int y);

        // returns a sprite obj
        sf::Sprite loadImage();

        /*
        */
        std::shared_ptr<baseItem> getItemStored();

        void setImage(std::string image_path);

        virtual void initilizeSprite();

        sf::FloatRect getRect();

        bool isOpened() { return opened; }

        void setOpened() { opened = true; }

    private:

        bool opened = false;
        std::shared_ptr<baseItem> m_item = nullptr;
};




#endif
