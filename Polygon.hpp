#ifndef POLYGON_HPP_INCLUDED
#define POLYGON_HPP_INCLUDED

// Program specific:
#include "Vertex.hpp"
#include "Color.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:


namespace sf3
{

    class Polygon : public sf::Drawable
    {
        Polygon();
        Polygon(const Polygon &polygon);
        ~Polygon();

        void operator=(const Polygon &polygon);
        Vertex &operator[](std::size_t pos);

        void setPosition(sf::Vector3f position);
        const sf::Vector3f &getPosition() const;

        void setFillColor(sf::Color color);
        void setFillColor(Color color);
        const Color &getFillColor() const;

    private:

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        sf::Vector3f m_position;

        float m_angle;
        sf::Vector3f m_rotation;

        std::vector<Vertex> vertices;

    };

} // Namespace sf3

#endif // POLYGON_HPP_INCLUDED
