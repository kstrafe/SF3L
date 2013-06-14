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

#include "Polygon.hpp"


namespace sf3
{

    Polygon::Polygon()
    :
    m_position(sf::Vector3f(0.f, 0.f, 0.f)),
    m_angle(0.f),
    m_rotation(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Polygon::Polygon(const Polygon &polygon)
    :
    m_position(polygon.m_position),
    m_angle(polygon.m_angle),
    m_rotation(polygon.m_rotation)
    {}


    Polygon::~Polygon()
    {}


    void Polygon::operator=(const Polygon &polygon)
    {
        m_position = polygon.m_position;
        m_angle = polygon.m_angle;
        m_rotation = polygon.m_rotation;
    }


    Vertex &Polygon::operator[](std::size_t pos)
    {
        return std::ref(vertices[pos]);
    }


    void Polygon::setPosition(sf::Vector3f position)
    {
        m_position = position;
    }


    const sf::Vector3f &Polygon::getPosition() const
    {
        return std::ref(m_position);
    }


    void Polygon::setFillColor(sf::Color color)
    {
        for (Vertex &vert : vertices)
            vert.setColor(color);
    }


    void Polygon::setFillColor(Color color)
    {
        for (Vertex &vert : vertices)
            vert.setColor(color);
    }


    const Color &Polygon::getFillColor() const
    {
        return std::cref(vertices[0].getColor());
    }


    // PRIVATE:


    void Polygon::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        // Transformations to all vertices
        glTranslatef(m_position.x, m_position.y, m_position.z);
        glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);

        glBegin(GL_POLYGON);
        for (const Vertex &vert : vertices)
        {
            glColor3f(vert.m_color.r, vert.m_color.g, vert.m_color.b);
            glVertex3f(vert.m_position.x, vert.m_position.y, vert.m_position.z);
        }
        glEnd();

        glPopMatrix();
    }

} // Namespace sf3
