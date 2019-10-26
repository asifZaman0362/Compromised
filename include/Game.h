#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Settings.h"
#include "SceneManager.h"

class Game
{
public:
    Game(Settings);
    ~Game();

    void Start();
    void Quit();

private:
    void Update(float);
    void Draw(float);
    void Input();
    void Resize(float, float);

    Settings settings;
    sf::ContextSettings ctxSettings;
    sf::VideoMode videoMode;
    sf::RenderWindow window;
    sf::Clock mainClock;
    bool isRunning;
};