#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include <SFML/Graphics.hpp>

class Weapon {
private:
    sf::Texture arrow;
    sf::Vector2f arrowDirection;
    sf::RectangleShape BoundingRectangle;

public:
    float m_arrowSpeed;
    int Xarrow = 4;
    int Yarrow = 3;
    sf::Sprite arrowSprite;

public:
    Weapon();
    ~Weapon();
    void Initialize(const sf::Vector2f &position, sf::Vector2f &target, float arrowSpeed);
    void Load();
    void Update(float);
    void Draw(sf::RenderWindow*);
    inline const sf::FloatRect GetGlobalBounds() {
        return arrowSprite.getGlobalBounds();
    }
};

#endif // WEAPON_H

