#include <iostream>
#include "SceneManager.h"

std::stack<ScenePtr> SceneManager::scenes;

SceneManager::~SceneManager()
{
    DestroyAll();
}

void SceneManager::LoadScene(ScenePtr scene, bool rmExisting)
{
    if (rmExisting && !scenes.empty())
    {
        scenes.pop();
    }
    scenes.push(std::move(scene));
    GetCurrentScene().Init();
}

void SceneManager::DestroyAll()
{
    while (!scenes.empty())
    {
        scenes.top()->CleanUp();
        scenes.top().reset();
        scenes.pop();
    }
}

Scene& SceneManager::GetCurrentScene()
{
    return *scenes.top().get();
}
