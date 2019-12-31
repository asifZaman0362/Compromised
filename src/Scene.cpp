#include "Scene.hpp"
#include <iostream>

using namespace TstBits;

Scene::Scene()
{
    std::cout << "Created scene.\n";
}

Scene::~Scene()
{
    std::cout << "Destroyed Scene.\n";
    for (sf::Drawable* item : drawables)
    {
        delete item;
    }
}

void Scene::Start()
{
    state = Running;
}

void Scene::Draw(sf::RenderTarget &target, float dt)
{
    target.setActive(false);
    target.pushGLStates();
    target.clear(sf::Color::Blue);
    for (auto var : drawables)
    {
        target.draw(*var);
    }
    target.popGLStates();
}

void Scene::Pause()
{
    state = Paused;
}

SceneState Scene::GetState()
{
    return state;
}