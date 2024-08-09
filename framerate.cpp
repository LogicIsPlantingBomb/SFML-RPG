#include "framerate.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Framerate::Framerate() : Timer(0) {}

void Framerate::Initialize() {}

void Framerate::Load() {
    if (font.loadFromFile("./GothamRounded/Gotham Rounded Medium/Gotham Rounded Medium.otf")) {
        std::cout << "font loaded" << std::endl;
        framerate.setFont(font);
        framerate.setFillColor(sf::Color::Black);
        framerate.setCharacterSize(32);
        framerate.setPosition(10, 10);
    } else {
        std::cout << "Font not loaded\n";
    }
}

void Framerate::Update(double deltaTime) {
    Timer += deltaTime;
    if (Timer >= 2000.0) {
        double result = 1000.0 / deltaTime;
        std::string frameratetext = "FPS: " + std::to_string(static_cast<int>(result)) + "  Frame Time:  " + std::to_string(deltaTime);
        framerate.setString(frameratetext);
    }
}

void Framerate::Draw(sf::RenderWindow* window) {
    window->draw(framerate);
}

