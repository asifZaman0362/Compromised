#include <SFML/Graphics.hpp>
#include "ApplicationStats.hpp"

namespace TstBits {
    namespace UiUtils {
        inline sf::Vector2f CenterObjectToParent2D(sf::FloatRect object, sf::FloatRect parent) {
            sf::Vector2f newPos;
            newPos.x = (parent.width/2) - (object.width/2);
            newPos.y = (parent.height/2) - (object.height/2);
            return newPos;
        }

        inline sf::Vector2f CenterObjectToScreen2D(sf::FloatRect object) {
            sf::Vector2f newPos;
            float pW = (float) ApplicationStats::m_settings->width;
            float pH = (float) ApplicationStats::m_settings->height;
            newPos.x = (pW / 2) - (object.width / 2);
            newPos.y = (pH / 2) - (object.height / 2);
            return newPos;
        }
    };
}