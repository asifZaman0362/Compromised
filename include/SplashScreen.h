#pragma once
#include "Scene.h"

class SplashScreen : public Scene
{
public:
    SplashScreen();
    ~SplashScreen();

    void Init();
    void Start() override;
    void Setup(sf::RenderWindow&);
    void Update(float);
    void Draw(sf::RenderTarget&, float = 0.1666f) override;
    void CleanUp();
private:
    float timer;
    int vertices;
};