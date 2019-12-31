#include "Settings.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace TstBits {
    class ApplicationStats
    {
    public:
        ApplicationStats();
        ~ApplicationStats() = default;

        static Settings* m_settings;
        static sf::RenderWindow* m_window;
    };
}