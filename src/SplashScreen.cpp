#include <iostream>
#include "SplashScreen.h"

SplashScreen::SplashScreen() : Scene::Scene() 
{
    std::cout << "Created SplashScreen Scene.\n";
}

SplashScreen::~SplashScreen() 
{
    std::cout << "Destroying";
}

void SplashScreen::Init()
{
    std::cout << "Init Splash." << std::endl;
    timer = 0;
    sf::Texture* bgTexture = AssetManager::LoadTexture("background");
    drawables.push_back(new sf::Sprite(*bgTexture));
}

void SplashScreen::Update(float dt)
{
    timer += dt;
    if (timer >= 3)
    {
        std::cout << "FU!";
    }
}

void SplashScreen::CleanUp()
{
    AssetManager::ClearAll();
}