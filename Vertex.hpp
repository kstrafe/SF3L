#ifndef VERTEX_HPP_INCLUDED
#define VERTEX_HPP_INCLUDED

// Program specific:
#include "Color.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:


namespace sf3
{

    class Vertex : public sf::Drawable
    {
    public:

        Vertex
        (
            sf::Vector3f position = sf::Vector3f(0.f, 0.f, 0.f),
            sf::Color color = sf::Color(255, 255, 255)
        );
        Vertex(const Vertex &vertex);
        void operator=(const Vertex &vertex);
        ~Vertex();


        void setColor(sf::Color color);
        void setColor(Color color);
        const Color &getColor() const;

        void setPosition(sf::Vector3f position);
        const sf::Vector3f &getPosition() const;


        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    private:

        sf::Vector3f m_position;
        sf3::Color m_color;

        friend class Triangle;
        friend class Rectangle;
        friend class Polygon;
    };

} // Namespace sf3
#endif // VERTEX_HPP_INCLUDED
