#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"


enum SceneState {
    Running, Paused, Inactive
};

class Scene 
{
public:
    Scene();
    ~Scene();

    virtual void Init() = 0;
    virtual void Setup(sf::RenderWindow&) = 0;
    virtual void Start();
    virtual void Update(float) = 0;
    virtual void Draw(sf::RenderTarget&, float = 0.1666f);
    virtual void Pause();
    virtual void CleanUp() = 0;
    SceneState GetState();
protected:
    SceneState state;
    int index;
    std::vector<sf::Drawable*> drawables;
};