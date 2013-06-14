#ifndef TEXTURABLE_HPP_INCLUDED
#define TEXTURABLE_HPP_INCLUDED

// Program specific:
#include "Vertex.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    class Texturable
    {
    public:

        Texturable();
        Texturable(sf::Texture *texture, const sf::Vector2f &repetition);
        virtual ~Texturable();

        void setTexture(sf::Texture &texture);
        void setRepeated(const sf::Vector2f &st);
        void setRepeated(const bool state = true);

    protected:

        sf::Texture *m_texture;
        sf::Vector2f m_repetition;
    };

} // Namespace sf3


#endif // TEXTURABLE_HPP_INCLUDED
