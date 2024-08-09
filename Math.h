#ifndef MATH_H
#define MATH_H

#include <vector>
#include <SFML/Graphics.hpp>

class Math {
public:
    static sf::Vector2f NormalizeVector(sf::Vector2f vector);
    bool CollisionRect(sf::FloatRect, sf::FloatRect);
};

#endif // MATH_H

