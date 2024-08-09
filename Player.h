#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <vector>
#include "Math.h"
#include "Weapon.h"

class Enemy;

class Player {
private:
    sf::Texture player;
    sf::RectangleShape BoundingRectangle;

public:
    Weapon arrow;
    float PlayerHealth;
    sf::Text PlayerText;
    sf::Font PlayerFont;
    int collisionVariable = 0;
    Math math;
    float maxFirerate;
    float FirerateTimer;
    float playerSpeed;
    float height = 2.0f;
    float width = 2.0f;
    int XPixel = 64;
    int YPixel = 64;
    sf::Sprite playerSprite;
    std::vector<Weapon> arrows;
    float arrowSpeed;

public:
    Player();
    ~Player();
    void ChangeHPlayer(float);
    void Initialize();
    void Load();
    void Update(Enemy*, float, sf::Vector2f);
    void Draw(sf::RenderWindow*);
};

#endif // PLAYER_H

