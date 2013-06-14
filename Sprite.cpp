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

#include "Sprite.hpp"

namespace sf3
{

    Sprite::Sprite()
    :
    Movable(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Sprite::Sprite(const Sprite &sprite)
    :
    Movable(sprite.m_position),
    Rotatable(sprite.m_angle, sprite.m_rotation),
    Texturable(sprite.m_texture, sprite.m_repetition),
    m_vertices(sprite.m_vertices)
    {}


    Sprite::~Sprite()
    {}


    void Sprite::operator=(const Sprite &sprite)
    {
        m_vertices[0] = sprite.m_vertices[0];
        m_vertices[1] = sprite.m_vertices[1];
        m_vertices[2] = sprite.m_vertices[2];
        m_position = sprite.m_position;
        m_texture = sprite.m_texture;
    }


    NocolVertex &Sprite::topLeft()
    {
        return std::ref(m_vertices[0]);
    }


    NocolVertex &Sprite::topRight()
    {
        return std::ref(m_vertices[1]);
    }


    NocolVertex &Sprite::bottomRight()
    {
        return std::ref(m_vertices[2]);
    }


    NocolVertex &Sprite::bottomLeft()
    {
        return std::ref(m_vertices[3]);
    }


    void Sprite::setFillColor(const sf::Color &color)
    {
        m_color = color;
    }


    void Sprite::setFillColor(const Color &color)
    {
        m_color = color;
    }


    const Color &Sprite::getFillColor() const
    {
        return std::cref(m_color);
    }


    void Sprite::computeNormal()
    {
        sf::Vector3f
            zero1(m_vertices[1].getPosition() - m_vertices[0].getPosition()),
            zero3(m_vertices[3].getPosition() - m_vertices[0].getPosition());

        m_normal.x /*= y3z2z3y2*/ = zero3.y * zero1.z - zero3.z * zero1.y;
        m_normal.y = zero3.z * zero1.x - zero3.x * zero1.z;
        m_normal.z = zero3.x * zero1.y - zero3.y * zero1.x;

        float len = std::sqrt(m_normal.x * m_normal.x + m_normal.y * m_normal.y + m_normal.z * m_normal.z);
        m_normal.x /= len;
        m_normal.y /= len;
        m_normal.z /= len;

        std::cout << "x: " << m_normal.x << " y: " << m_normal.y << " z: " << m_normal.z << std::endl;
    }


    void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        glEnable(GL_TEXTURE_2D);

        glTranslatef(m_position.x, m_position.y, m_position.z);
        glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        sf::Texture::bind(m_texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glColor3f(m_color.r, m_color.g, m_color.b);
        glNormal3f(m_normal.x, m_normal.y, m_normal.z);

        if (m_texture && m_texture->isRepeated())
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            glBegin(GL_QUADS);
                glTexCoord2d(0.f, 0.f);
                glVertex3f(m_vertices[0].m_position.x, m_vertices[0].m_position.y, m_vertices[0].m_position.z);

                glTexCoord2d(m_repetition.x, 0.f);
                glVertex3f(m_vertices[1].m_position.x, m_vertices[1].m_position.y, m_vertices[1].m_position.z);

                glTexCoord2d(m_repetition.x, m_repetition.y);
                glVertex3f(m_vertices[2].m_position.x, m_vertices[2].m_position.y, m_vertices[2].m_position.z);

                glTexCoord2d(0.f, m_repetition.y);
                glVertex3f(m_vertices[3].m_position.x, m_vertices[3].m_position.y, m_vertices[3].m_position.z);
            glEnd();

        }
        else
        {
            glBegin(GL_QUADS);
                glTexCoord2d(0.f, 0.f);
                glVertex3f(m_vertices[0].m_position.x, m_vertices[0].m_position.y, m_vertices[0].m_position.z);

                glTexCoord2d(1.f, 0.f);
                glVertex3f(m_vertices[1].m_position.x, m_vertices[1].m_position.y, m_vertices[1].m_position.z);

                glTexCoord2d(1.f, 1.f);
                glVertex3f(m_vertices[2].m_position.x, m_vertices[2].m_position.y, m_vertices[2].m_position.z);

                glTexCoord2d(0.f, 1.f);
                glVertex3f(m_vertices[3].m_position.x, m_vertices[3].m_position.y, m_vertices[3].m_position.z);
            glEnd();
        }

        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    }

} // Namespace sf3
