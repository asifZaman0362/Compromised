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
    while(isRunning)
    {
        // Create the main window
        window.create(sf::VideoMode(800, 600), settings.title, settings.window_style, ctxSettings);
        window.setVerticalSyncEnabled(true);

        window.setActive(true);
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glClearDepth(1.f);
        glDisable(GL_LIGHTING);
        glViewport(0, 0, window.getSize().x, window.getSize().y);

        // Setup a perspective projection
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
        glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        SceneManager::GetCurrentScene().Setup(window);
        SceneManager::GetCurrentScene().Start();
        window.setActive(false);
        
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

            window.setActive(true);
            // Clear the depth buffer
            glClear(GL_DEPTH_BUFFER_BIT);
            Input();
            Update(frameClock.getElapsedTime().asSeconds());
            Draw(frameClock.getElapsedTime().asSeconds());
            // Make the window no longer the active window for OpenGL calls
            window.setActive(false);
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

