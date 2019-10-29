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

void SplashScreen::Setup(sf::RenderWindow& window)
{
    window.setActive(true);
    glEnable(GL_TEXTURE_2D);
    sf::Texture::bind(AssetManager::LoadTexture("texture"));
    GLfloat* vertexPtr, normalPtr, texcoordPtr;
    AssetManager::LoadModel("model");
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
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