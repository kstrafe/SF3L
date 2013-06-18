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

#include "Sphere.hpp"


namespace sf3
{

    Sphere::Sphere()
    :
    m_radius(0.f),
    m_display_list(glGenLists(1)),
    m_quadric(gluNewQuadric())
    {
        std::cout << m_display_list << std::endl;
    }


    Sphere::~Sphere()
    {
        gluDeleteQuadric(m_quadric);
        glDeleteLists(m_display_list, 1);
    }


    void Sphere::operator=(const Sphere &sphere)
    {
        m_color = sphere.m_color;
        m_radius = sphere.m_radius;

        glNewList(m_display_list, GL_COMPILE);
        gluSphere(m_quadric, m_radius, 30000, 30000);
        glEndList();
    }


    void Sphere::setRadius(const float radius)
    {
        m_radius = radius;

        glNewList(m_display_list, GL_COMPILE);
        gluSphere(m_quadric, radius, 30000, 30000);
        glEndList();
    }


    const float Sphere::getRadius() const
    {
        return m_radius;
    }


    void Sphere::setFillColor(const Color &color)
    {
        m_color = color;
    }


    void Sphere::setFillColor(const sf::Color &color)
    {
        m_color = color;
    }


    const Color &Sphere::getFillColor() const
    {
        return m_color;
    }


    void Sphere::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();
            glTranslatef(m_position.x, m_position.y, m_position.z);
            glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
            glCallList(m_display_list);
        glPopMatrix();
    }

} // Namespace sf3
