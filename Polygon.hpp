////////////////////////////////////////////////////////////
//
// SF3L - Simple, Fast 3D Library
// Copyright © 2013 Kevin R. Stravers (macocio@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

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
