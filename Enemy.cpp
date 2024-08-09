#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : Health(100.0f) {}
Enemy::~Enemy() {}

void Enemy::ChangeHP(int hp) {
    Health += hp;
    EnemyText.setString(std::to_string(static_cast<int>(Health)));
}

void Enemy::Initialize() {
    BoundingRectangle.setFillColor(sf::Color::Transparent);
    BoundingRectangle.setSize(sf::Vector2f(XPixel * height, YPixel * width));
    BoundingRectangle.setOutlineThickness(2);
    BoundingRectangle.setOutlineColor(sf::Color::Blue);
}

void Enemy::Load() {
    if (enemy.loadFromFile("./lpc_entry/png/slash/BODY_skeleton.png")) {
        std::cout << "Enemy loaded";
        EnemySprite.setTexture(enemy);
        EnemySprite.setTextureRect(sf::IntRect(256, 128, 64, 64));
        EnemySprite.setPosition(sf::Vector2f(1500, 700));
        EnemySprite.setScale(height, width);
    }
    if (EnemyFont.loadFromFile("./GothamRounded/Gotham Rounded Medium/Gotham Rounded Medium.otf")) {
        std::cout << "font loaded" << std::endl;
        EnemyText.setFont(EnemyFont);
        EnemyText.setCharacterSize(32);
        EnemyText.setFillColor(sf::Color::Black);
        EnemyText.setString(std::to_string(static_cast<int>(Health)));
    } else {
        std::cout << "Font not loaded\n";
    }
}

void Enemy::Update(Player *player, float deltaTime) {
    BoundingRectangle.setPosition(EnemySprite.getPosition());
    EnemyText.setPosition(EnemySprite.getPosition());
    if (Health > 0 && player->PlayerHealth) {
        if (math.CollisionRect(player->playerSprite.getGlobalBounds(), EnemySprite.getGlobalBounds())) {
            player->ChangeHPlayer(-0.01);
            std::cout << "Player Health: " << player->PlayerHealth << std::endl;
        }
    }
}

void Enemy::Draw(sf::RenderWindow *window) {
    if (Health > 0) {
        window->draw(BoundingRectangle);
        window->draw(EnemySprite);
        window->draw(EnemyText);
    }
}

