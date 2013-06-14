#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

// Program specific:
#include "NocolVertex.hpp"
#include "Movable.hpp"
#include "Rotatable.hpp"
#include "Colorable.hpp"
#include "Texturable.hpp"
#include "Color.hpp"
#include "Normalizable.hpp"

// Utilities:

// Standard Library components:
#include <iostream>

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    class Sprite
    :
    public sf::Drawable,
    public Movable,
    public Rotatable,
    public Colorable,
    public Texturable,
    public Normalizable
    {
    public:

        Sprite();
        Sprite(const Sprite &sprite);
        ~Sprite();

        void operator=(const Sprite &sprite);

        NocolVertex &topLeft();
        NocolVertex &topRight();
        NocolVertex &bottomRight();
        NocolVertex &bottomLeft();

        virtual void setFillColor(const sf::Color &color);
        virtual void setFillColor(const Color &color);
        const Color &getFillColor() const;

        virtual void computeNormal();

    private:

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        NocolVertex m_vertices[4];

        Color m_color;
    };

} // Namespace sf3

#endif // SPRITE_HPP_INCLUDED
