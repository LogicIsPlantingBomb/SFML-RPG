#include <iostream>
#include "Weapon.h"
#include "Math.h"

Weapon::Weapon() : m_arrowSpeed(0.0f) {}
Weapon::~Weapon() {}

void Weapon::Initialize(const sf::Vector2f &position, sf::Vector2f &target, float arrowSpeed) {
    m_arrowSpeed = arrowSpeed;
    arrowSprite.setScale(1.5, 1.5);
    arrowSprite.setPosition(position);
    arrowDirection = Math::NormalizeVector(target - position);
}

void Weapon::Load() {
    arrow.loadFromFile("./lpc_entry/png/bow/WEAPON_arrow.png");
    arrowSprite.setTexture(arrow); 
    arrowSprite.setTextureRect(sf::IntRect(Xarrow * 64, Yarrow * 64, 64, 64));
    arrowSprite.rotate(20);
    // Uncomment the following code if BoundingRectangle is required
    // sf::FloatRect arrowSpriteBounds = arrowSprite.getGlobalBounds();
    // BoundingRectangle.setFillColor(sf::Color::Transparent);
    // BoundingRectangle.setSize(sf::Vector2f(arrowSpriteBounds.height, arrowSpriteBounds.width));
    // BoundingRectangle.setOutlineThickness(2);
    // BoundingRectangle.setOutlineColor(sf::Color::Black);
}

void Weapon::Update(float deltaTime) {
    arrowSprite.setPosition(arrowSprite.getPosition() + arrowDirection * m_arrowSpeed * deltaTime);
    // Uncomment the following line if BoundingRectangle is required
    // BoundingRectangle.setPosition(arrowSprite.getPosition().x, arrowSprite.getPosition().y);
}

void Weapon::Draw(sf::RenderWindow* window) {
    window->draw(arrowSprite);
    // Uncomment the following line if BoundingRectangle is required
    // window->draw(BoundingRectangle);
}

