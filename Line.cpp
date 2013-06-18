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
#include "Line.hpp"


namespace sf3
{

    ////////////////////////////////////////////////////////////
    Line::Line()
    :
    m_point({sf::Vector3f(0.f, 0.f, 0.f), sf::Vector3f(3.f, 0.f, 0.f)}),
    m_displist(glGenLists(cm_display_list_amount)),
    m_width(1.f)
    {
        glNewList(m_displist + cm_begin_end_wrap, GL_COMPILE);
            glCallList(m_displist + cm_translation); // Set the correct world space position
            glCallList(m_displist + cm_rotation); // Correctly rotate the object.
            glCallList(m_displist + cm_line_width); // Set the correct width first

            glCallList(m_displist + cm_color_1); // Then set the color
            glBegin(GL_LINES);
                glCallList(m_displist + cm_position_1); // Then set the color
                glCallList(m_displist + cm_color_2); // Then set the second color
                glCallList(m_displist + cm_position_2); // Then set the second position
            glEnd(); // Finish the line
        glEndList();

        glNewList(m_displist + cm_line_width, GL_COMPILE);
            glLineWidth(m_width);
        glEndList();

        glNewList(m_displist + cm_color_1, GL_COMPILE);
            glColor4f(m_color[0].r, m_color[0].g, m_color[0].b, m_color[0].a);
        glEndList();

        glNewList(m_displist + cm_position_1, GL_COMPILE);
            glVertex3f(m_point[0].x, m_point[0].y, m_point[0].z);
        glEndList();

        glNewList(m_displist + cm_color_2, GL_COMPILE);
            glColor4f(m_color[1].r, m_color[1].g, m_color[1].b, m_color[1].a);
        glEndList();

        glNewList(m_displist + cm_position_2, GL_COMPILE);
            glVertex3f(m_point[1].x, m_point[1].y, m_point[1].z);
        glEndList();

        glNewList(m_displist + cm_translation, GL_COMPILE);
            glTranslatef(m_position.x, m_position.y, m_position.z);
        glEndList();

        glNewList(m_displist + cm_rotation, GL_COMPILE);
            glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    Line::~Line()
    {}

    ////////////////////////////////////////////////////////////
    void Line::move(const sf::Vector3f &offset)
    {
        Movable::move(std::forward<decltype(offset)>(offset));
    }

    ////////////////////////////////////////////////////////////
    void Line::setPosition(const sf::Vector3f &value)
    {
        Movable::setPosition(std::forward<decltype(value)>(value));


    }

    ////////////////////////////////////////////////////////////
    const sf::Vector3f &Line::getPosition() const
    {
        return std::cref(Movable::getPosition());
    }

    ////////////////////////////////////////////////////////////
    void Line::setFillColor(const sf::Color &color)
    {
        setFillColor(Color(color));
    }

    ////////////////////////////////////////////////////////////
    void Line::setFillColor(const Color &color)
    {
        m_color[0] = color;
        m_color[1] = color;

        glNewList(m_displist + cm_color_1, GL_COMPILE);
            glColor4f(m_color[0].r, m_color[0].g, m_color[0].b, m_color[0].a);
        glEndList();

        glNewList(m_displist + cm_color_2, GL_COMPILE);
            glColor4f(m_color[1].r, m_color[1].g, m_color[1].b, m_color[1].a);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    const Color &Line::getFillColor() const
    {
        return std::cref(m_color[0]);
    }

    ////////////////////////////////////////////////////////////
    void Line::setRotation(const float angle)
    {
        Rotatable::setRotation(std::forward<decltype(angle)>(angle));

        // Need to recompile the rotation matrix
        glNewList(m_displist + cm_rotation, GL_COMPILE);
            glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::setRotation(const float angle, const sf::Vector3f &dispersion)
    {
        Rotatable::setRotation(std::forward<decltype(angle)>(angle), std::forward<decltype(dispersion)>(dispersion));

        // Need to recompile the rotation matrix
        glNewList(m_displist + cm_rotation, GL_COMPILE);
            glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::setRotation(const sf::Vector3f &dispersion)
    {
        Rotatable::setRotation(std::forward<decltype(dispersion)>(dispersion));

        // Need to recompile the rotation matrix
        glNewList(m_displist + cm_rotation, GL_COMPILE);
            glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::rotate(const float angle)
    {
        Rotatable::rotate(std::forward<decltype(angle)>(angle));

        // Need to recompile the rotation matrix
        glNewList(m_displist + cm_rotation, GL_COMPILE);
            glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::rotate(const float angle, const sf::Vector3f &dispersion)
    {
        Rotatable::rotate(std::forward<decltype(angle)>(angle), std::forward<decltype(dispersion)>(dispersion));

        // Need to recompile the rotation matrix
        glNewList(m_displist + cm_rotation, GL_COMPILE);
            glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::rotate(const sf::Vector3f &dispersion)
    {
        Rotatable::rotate(std::forward<decltype(dispersion)>(dispersion));

        // Need to recompile the rotation matrix
        glNewList(m_displist + cm_rotation, GL_COMPILE);
            glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::setPointAColor(const Color &color)
    {
        m_color[0] = color;

        glNewList(m_displist + cm_color_1, GL_COMPILE);
            glColor4f(m_color[0].r, m_color[0].g, m_color[0].b, m_color[0].a);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::setPointBColor(const Color &color)
    {
        m_color[1] = color;

        glNewList(m_displist + cm_color_2, GL_COMPILE);
            glColor4f(m_color[1].r, m_color[1].g, m_color[1].b, m_color[1].a);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::setPointAPosition(const sf::Vector3f &value)
    {
        m_point[0] = value;

        glNewList(m_displist + cm_position_1, GL_COMPILE);
            glVertex3f(m_point[0].x, m_point[0].y, m_point[0].z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::setPointBPosition(const sf::Vector3f &value)
    {
        m_point[1] = value;

        glNewList(m_displist + cm_position_2, GL_COMPILE);
            glVertex3f(m_point[1].x, m_point[1].y, m_point[1].z);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    void Line::setLineWidth(const float width)
    {
        m_width = width;

        glNewList(m_displist + cm_line_width, GL_COMPILE);
            glLineWidth(m_width);
        glEndList();
    }

    ////////////////////////////////////////////////////////////
    const float Line::getLineWidth() const
    {
        return m_width;
    }

    ////////////////////////////////////////////////////////////
    void Line::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glCallList(m_displist + cm_begin_end_wrap);
    }

} // Namespace sf3










