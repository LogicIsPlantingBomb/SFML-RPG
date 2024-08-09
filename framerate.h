#ifndef FRAMERATE_H
#define FRAMERATE_H

#include <SFML/Graphics.hpp>

class Framerate {
    private:
        sf::Text framerate;
        sf::Font font;
        float Timer;
    public:
        Framerate();
        void Initialize();
        void Load();
        void Update(double deltaTime);
        void Draw(sf::RenderWindow *);
};

#endif // FRAMERATE_H

