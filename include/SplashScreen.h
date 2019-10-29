#pragma once
#include "Scene.h"

class SplashScreen : public Scene
{
public:
    SplashScreen();
    ~SplashScreen();

    void Init();
    void Setup(sf::RenderWindow&);
    void Update(float);
    void CleanUp();
private:
    float timer;
};