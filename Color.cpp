#include "Color.hpp"


namespace sf3
{

    Color::Color()
    :
    r(1.f),
    g(1.f),
    b(1.f)
    {}


    Color::Color(sf::Color color)
    :
    r(color.r / 255.f),
    g(color.g / 255.f),
    b(color.b / 255.f)
    {}


    Color::~Color()
    {}


    void Color::operator=(const Color &color)
    {
        r = color.r;
        g = color.g;
        b = color.b;
    }

} // Namespace sf3
