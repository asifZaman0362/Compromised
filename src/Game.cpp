#include "Game.h"
#include "SplashScreen.h"

Game::Game(Settings settings) : settings(settings)
{
    ctxSettings.depthBits = settings.depth_bits;
    ctxSettings.sRgbCapable = settings.srgb;
    videoMode = sf::VideoMode(settings.width, settings.height);
    ScenePtr splashScreen = std::make_unique<SplashScreen>();
    SceneManager::LoadScene(std::move(splashScreen));
}

Game::~Game() = default;

void Game::Start()
{
    isRunning = true;
    mainClock.restart();
    sf::Clock frameClock;
    SceneManager::GetCurrentScene().Start();
    while(isRunning)
    {
        window.create(videoMode, settings.title, settings.window_style, ctxSettings);
        window.setVerticalSyncEnabled(settings.vsync);
        
        while(window.isOpen())
        {
            sf::Event e;
            while(window.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                {
                    Quit();
                    return;
                }
                else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
                {
                    Quit();
                    return;
                }
                else if (e.type == sf::Event::Resized)
                {
                    Resize(e.size.width, e.size.height);
                }
            }
            Input();
            Update(frameClock.getElapsedTime().asSeconds());
            Draw(frameClock.getElapsedTime().asSeconds());
            frameClock.restart();
        }
    }
}

void Game::Update(float dt)
{
    if (SceneManager::GetCurrentScene().GetState() == SceneState::Running)
    {
        SceneManager::GetCurrentScene().Update(dt);
    }
}

void Game::Draw(float dt)
{
    //window.clear(sf::Color::Black);
    SceneManager::GetCurrentScene().Draw(window);
    window.display();
}

void Game::Resize(float width, float height)
{
    // Setup GLViewport and Frustum
}

void Game::Input()
{

}

void Game::Quit()
{
    isRunning = false;
    window.close();
    // Delete stuff
    SceneManager::DestroyAll();
}

