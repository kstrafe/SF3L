#ifndef COLOR_HPP_INCLUDED
#define COLOR_HPP_INCLUDED

// Program specific:

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    struct Color
    {
        Color();
        Color(sf::Color color);
        ~Color();

        void operator=(const Color &color);

        float r, g, b;
    };

} // Namespace sf3

#endif // COLOR_HPP_INCLUDED
