#include "Scene.h"
#include <iostream>

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
    for (auto var : drawables)
    {
        target.clear(sf::Color::Blue);
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