#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED

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

    class Triangle : public sf::Drawable
    {
    public:

        Triangle();
        Triangle(const Triangle &triangle);
        ~Triangle();

        void operator=(const Triangle &triangle);
        Vertex &operator[](std::size_t pos);

        void setPosition(sf::Vector3f position);
        void setFillColor(sf::Color color);

    private:

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        Vertex m_vertices[3];
        sf::Vector3f m_position;
    };

} // Namespace sf3

#endif // TRIANGLE_HPP_INCLUDED
