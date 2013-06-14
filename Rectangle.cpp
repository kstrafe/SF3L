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

#include "Rectangle.hpp"

namespace sf3
{

    Rectangle::Rectangle()
    {}


    Rectangle::Rectangle(const Rectangle &rectangle)
    :
    Movable(),
    Rotatable(),
    m_vertices(rectangle.m_vertices)
    {}


    Rectangle::~Rectangle()
    {}


    void Rectangle::operator=(const Rectangle &rectangle)
    {
        m_vertices[0] = rectangle.m_vertices[0];
        m_vertices[1] = rectangle.m_vertices[1];
        m_vertices[2] = rectangle.m_vertices[2];
        m_vertices[3] = rectangle.m_vertices[3];
        m_position = rectangle.m_position;
        m_angle = rectangle.m_angle;
        m_rotation = rectangle.m_rotation;
    }


    Vertex &Rectangle::topLeft()
    {
        return std::ref(m_vertices[0]);
    }


    Vertex &Rectangle::topRight()
    {
        return std::ref(m_vertices[1]);
    }


    Vertex &Rectangle::bottomRight()
    {
        return std::ref(m_vertices[2]);
    }


    Vertex &Rectangle::bottomLeft()
    {
        return std::ref(m_vertices[3]);
    }


    void Rectangle::setFillColor(const sf::Color &color)
    {
        m_vertices[0].setColor(color);
        m_vertices[1].setColor(color);
        m_vertices[2].setColor(color);
        m_vertices[3].setColor(color);
    }


    void Rectangle::setFillColor(const Color &color)
    {
        m_vertices[0].setColor(color);
        m_vertices[1].setColor(color);
        m_vertices[2].setColor(color);
        m_vertices[3].setColor(color);
    }


    const Color &Rectangle::getFillColor() const
    {
        return std::ref(m_vertices[0].getColor());
    }


    void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        glTranslatef(m_position.x, m_position.y, m_position.z);
        glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);

        glBegin(GL_QUADS);
            glColor3f(m_vertices[0].m_color.r, m_vertices[0].m_color.g, m_vertices[0].m_color.b);
            glVertex3f(m_vertices[0].m_position.x, m_vertices[0].m_position.y, m_vertices[0].m_position.z);

            glColor3f(m_vertices[1].m_color.r, m_vertices[1].m_color.g, m_vertices[1].m_color.b);
            glVertex3f(m_vertices[1].m_position.x, m_vertices[1].m_position.y, m_vertices[1].m_position.z);

            glColor3f(m_vertices[2].m_color.r, m_vertices[2].m_color.g, m_vertices[2].m_color.b);
            glVertex3f(m_vertices[2].m_position.x, m_vertices[2].m_position.y, m_vertices[2].m_position.z);

            glColor3f(m_vertices[3].m_color.r, m_vertices[3].m_color.g, m_vertices[3].m_color.b);
            glVertex3f(m_vertices[3].m_position.x, m_vertices[3].m_position.y, m_vertices[3].m_position.z);
        glEnd();

        glPopMatrix();
    }

} // Namespace sf3
