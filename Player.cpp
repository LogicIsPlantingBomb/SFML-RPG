#include "Player.h"
#include <iostream>

Player::Player() 
    : playerSpeed(2.0f), arrowSpeed(5.0f), maxFirerate(100), FirerateTimer(0), PlayerHealth(100.0f) {}

void Player::Initialize() {
    BoundingRectangle.setFillColor(sf::Color::Transparent);
    BoundingRectangle.setSize(sf::Vector2f(XPixel * height, YPixel * width));
    BoundingRectangle.setOutlineThickness(2);
    BoundingRectangle.setOutlineColor(sf::Color::Red);
}

Player::~Player() {}

void Player::ChangeHPlayer(float hp) {
    PlayerHealth += hp;
    PlayerText.setString(std::to_string(static_cast<int>(PlayerHealth)));
}

void Player::Load() {
    player.loadFromFile("./lpc_entry/png/slash/BODY_human.png");
    playerSprite.setTexture(player);
    int Xindex = 4;
    int Yindex = 2;
    playerSprite.setTextureRect(sf::IntRect(Xindex * XPixel, Yindex * YPixel, XPixel, YPixel));
    playerSprite.setPosition(sf::Vector2f(100, 100));
    playerSprite.setScale(height, width);
    arrow.Load();

    if (PlayerFont.loadFromFile("./GothamRounded/Gotham Rounded Medium/Gotham Rounded Medium.otf")) {
        std::cout << "font loaded" << std::endl;
        PlayerText.setFont(PlayerFont);
        PlayerText.setCharacterSize(32);
        PlayerText.setFillColor(sf::Color::Black);
        PlayerText.setString(std::to_string(static_cast<int>(PlayerHealth)));
    } else {
        std::cout << "Font not loaded\n";
    }
}

void Player::Update(Enemy *enemy, float deltaTime, sf::Vector2f getMousePosition) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(0.5, 0) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(0, -0.5) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(-0.5, 0) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(0, 0.5) * playerSpeed * deltaTime);
    }
    FirerateTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && FirerateTimer >= maxFirerate) {
        arrows.push_back(arrow);
        int i = arrows.size() - 1;
        arrows[i].Initialize(playerSprite.getPosition(), getMousePosition, arrowSpeed);		
        FirerateTimer = 0;
    }
    for (int i = 0; i < arrows.size(); i++) {
        arrows[i].Update(deltaTime);	
        if (enemy->Health > 0) {
            if (math.CollisionRect(arrows[i].GetGlobalBounds(), enemy->EnemySprite.getGlobalBounds())) {
                arrows.erase(arrows.begin() + i);
                std::cout << "enemy Health: " << enemy->Health << std::endl;
                enemy->ChangeHP(-10);
            }
        }
    }
    BoundingRectangle.setPosition(playerSprite.getPosition());
    if (PlayerHealth > 0 && enemy->Health > 0) {
        if (math.CollisionRect(playerSprite.getGlobalBounds(), enemy->EnemySprite.getGlobalBounds())) {
            std::cout << "Collision Detected: " << collisionVariable << std::endl;
            collisionVariable++;
        }
    }
    PlayerText.setPosition(playerSprite.getPosition());
}

void Player::Draw(sf::RenderWindow *window) {
    if (PlayerHealth > 0) {
        window->draw(playerSprite);
        window->draw(BoundingRectangle);
        for (int i = 0; i < arrows.size(); i++) {
            arrows[i].Draw(window);
        }
        window->draw(PlayerText);
    }
}

