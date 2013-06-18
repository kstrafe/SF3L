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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Vertex.hpp"


namespace sf3
{

    ////////////////////////////////////////////////////////////
    Vertex::Vertex
    (
        sf::Vector3f position,
        sf::Color color
    )
    :
    Movable(position),
    m_color(color),
    m_displist(glGenLists(cm_display_list_amount))
    {
        glNewList(m_displist + cm_color, GL_COMPILE);
            glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
        glEndList();

        glNewList(m_displist + cm_position, GL_COMPILE);
            glCallList(m_displist + cm_color);
            glBegin(GL_POINTS);
                glVertex3f(m_position.x, m_position.y, m_position.z);
            glEnd();
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    Vertex::Vertex(const Vertex &vertex)
    :
    Movable(vertex.m_position),
    m_color(vertex.m_color),
    m_displist(glGenLists(cm_display_list_amount))
    {
        Vertex();
    }

    ////////////////////////////////////////////////////////////
    void Vertex::operator=(const Vertex &vertex)
    {
        m_position = vertex.m_position;
        m_color = vertex.m_color;

        glNewList(m_displist + cm_color, GL_COMPILE);
            glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
        glEndList();

        glNewList(m_displist + cm_position, GL_COMPILE);
            glCallList(m_displist + cm_color);
            glBegin(GL_POINTS);
                glVertex3f(m_position.x, m_position.y, m_position.z);
            glEnd();
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    Vertex::~Vertex()
    {
        glDeleteLists(m_displist, cm_display_list_amount);
    }

    ////////////////////////////////////////////////////////////
    void Vertex::move(const sf::Vector3f &position)
    {
        m_position += position;
        Movable::move(position);

        glNewList(m_displist + cm_position, GL_COMPILE);
            glCallList(m_displist + cm_color);
            glBegin(GL_POINTS);
                glVertex3f(m_position.x, m_position.y, m_position.z);
            glEnd();
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Vertex::setPosition(const sf::Vector3f &position)
    {
        m_position = position;

        glNewList(m_displist + cm_position, GL_COMPILE);
            glCallList(m_displist + cm_color);
            glBegin(GL_POINTS);
                glVertex3f(m_position.x, m_position.y, m_position.z);
            glEnd();
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Vertex::setColor(const sf::Color &color)
    {
        m_color = color;

        glNewList(m_displist + cm_color, GL_COMPILE);
            glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Vertex::setColor(const Color &color)
    {
        m_color = color;

        glNewList(m_displist + cm_color, GL_COMPILE);
            glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    const Color &Vertex::getColor() const
    {
        return std::cref(m_color);
    }

    ////////////////////////////////////////////////////////////
    void Vertex::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glCallList(m_displist + cm_position);
    }

} // Namespace sf3
