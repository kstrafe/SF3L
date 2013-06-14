#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

// Program specific:
#include "Vertex.hpp"
#include "Movable.hpp"
#include "Rotatable.hpp"
#include "Colorable.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    class Rectangle
    :
    public sf::Drawable,
    public Movable,
    public Rotatable,
    public Colorable
    {
    public:

        Rectangle();
        Rectangle(const Rectangle &rectangle);
        ~Rectangle();

        void operator=(const Rectangle &rectangle);

        Vertex &topLeft();
        Vertex &topRight();
        Vertex &bottomRight();
        Vertex &bottomLeft();

        virtual void setFillColor(const sf::Color &color);
        virtual void setFillColor(const Color &color);
        virtual const Color &getFillColor() const;

    private:

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        Vertex m_vertices[4];
    };

} // Namespace sf3

#endif // RECTANGLE_HPP_INCLUDED
