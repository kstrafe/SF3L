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

#include "Vertex.hpp"


namespace sf3
{

    Vertex::Vertex
    (
        sf::Vector3f position,
        sf::Color color
    )
    :
    m_position(position),
    m_color(color)
    {}


    Vertex::Vertex(const Vertex &vertex)
    :
    m_position(vertex.m_position),
    m_color(vertex.m_color)
    {}


    void Vertex::operator=(const Vertex &vertex)
    {
        m_position = vertex.m_position;
        m_color = vertex.m_color;
    }


    Vertex::~Vertex()
    {}


    void Vertex::setPosition(sf::Vector3f position)
    {
        m_position = position;
    }


    void Vertex::setColor(sf::Color color)
    {
        m_color.r = color.r / 255.f;
        m_color.g = color.g / 255.f;
        m_color.b = color.b / 255.f;
    }


    void Vertex::setColor(Color color)
    {
        m_color = color;
    }


    const Color &Vertex::getColor() const
    {
        return std::cref(m_color);
    }


    const sf::Vector3f &Vertex::getPosition() const
    {
        return std::cref(m_position);
    }


    void Vertex::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();
        glColor3f(m_color.r, m_color.g, m_color.b);

        glBegin(GL_POINTS);
            glVertex3f(m_position.x, m_position.y, m_position.z);
        glEnd();

        glPopMatrix();
    }

} // Namespace sf3
