#include "Math.h"
#include <cmath>
#include <iostream>

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector) {
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizeVector;
    normalizeVector.x = vector.x / magnitude;
    normalizeVector.y = vector.y / magnitude;
    return normalizeVector;
}

bool Math::CollisionRect(sf::FloatRect rect1, sf::FloatRect rect2) {
    if (rect1.left + rect1.width > rect2.left &&
        rect2.left + rect1.width > rect1.left &&
        rect2.top + rect2.height > rect1.top &&
        rect1.top + rect1.height > rect2.top)
        return true;
    return false;
}

