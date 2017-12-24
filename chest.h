#ifndef chest_h
#define chest_h

#include <SFML/Graphics.hpp>
class chest {

    public:
        chest(int x, int y);
        // returns a sprite obj
        sf::Sprite loadImage();

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        int x_val;
        int y_val;
};




#endif
