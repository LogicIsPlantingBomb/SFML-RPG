#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"
#include "Math.h"
#include <SFML/Graphics.hpp>

class Player;

class Enemy {
private:
    sf::Texture enemy;
    sf::RectangleShape BoundingRectangle;

public:
    Math math;
    sf::Text EnemyText;
    sf::Font EnemyFont;
    sf::Sprite EnemySprite;
    float Health;
    int XPixel = 64;
    int YPixel = 64;
    float height = 2.0f;
    float width = 2.0f;

public:
    Enemy();
    ~Enemy(); 
    void ChangeHP(int);
    void Initialize();
    void Load();
    void Update(Player*, float);
    void Draw(sf::RenderWindow*);
}; 

#endif // ENEMY_H

