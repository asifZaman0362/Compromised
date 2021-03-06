#include <iostream>
#include "SplashScreen.hpp"
#include "UiUtils.hpp"

using namespace TstBits;

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
    sf::Font* splashFont = AssetManager::LoadFont("ShareTech");
    splashText = new sf::Text("362Bits", *splashFont, 40);
    splashText->setFillColor(sf::Color::Red);
    drawables.push_back(splashText);
}

void SplashScreen::Start()
{
    Scene::Start();
    timer = 0;
}

void SplashScreen::Setup(sf::RenderWindow& window)
{
    //window.setActive(true);
    glEnable(GL_TEXTURE_2D);
    sf::Texture::bind(AssetManager::LoadTexture("texture"));
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    Mesh* model = AssetManager::LoadModel("model");
    vertices = model->GetVertexCount();
    glDisableClientState(GL_COLOR_ARRAY);
    // It works but I don't know how, or why
    // But I'm not going to mess with it or else it'll break
}

void SplashScreen::Update(float dt)
{
    timer += dt;
    splashText->setPosition(UiUtils::CenterObjectToScreen2D(splashText->getGlobalBounds())+sf::Vector2f(0, 200));
}

void SplashScreen::Draw(sf::RenderTarget& target, float dt)
{
    Scene::Draw(target);
    target.setActive(true);
    // Apply some transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -100.f);
    glRotatef(45.f, 1.f, 0.f, 0.f);
    glRotatef(timer * 30.f, 0.f, 1.f, 0.f);
    glRotatef(timer * 90.f, 0.f, 0.f, 1.f);

    // Draw the model
    glDrawArrays(GL_TRIANGLES, 0, vertices/3);
}

void SplashScreen::CleanUp()
{
    AssetManager::ClearAll();
}