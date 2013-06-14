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

#include "Mesh.hpp"

namespace sf3
{

    Mesh::Mesh()
    {}


    Mesh::Mesh(const Mesh &mesh)
    :
    m_drawables(mesh.m_drawables),
    Movable(mesh.m_position),
    Rotatable(mesh.m_angle, mesh.m_rotation)
    {}


    Mesh::~Mesh()
    {}


    void Mesh::operator=(const Mesh &mesh)
    {
        m_drawables = mesh.m_drawables;
        m_position = mesh.m_position;
        m_angle = mesh.m_angle;
        m_rotation = mesh.m_rotation;
    }


    sf::Drawable &Mesh::operator[](std::size_t pos)
    {
        return std::ref(*m_drawables[pos]);
    }


    void Mesh::add(sf::Drawable &drawable)
    {
        m_drawables.push_back(&drawable);
    }


    void Mesh::erase(const std::size_t pos)
    {
        m_drawables.erase(m_drawables.begin() + pos);
    }


    void Mesh::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        // Apply mesh's own transformations
        glTranslatef(m_position.x, m_position.y, m_position.z);
        glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);

        // TODO: Insert glBegin(GL_TRIANGLES) here to increase draw speed.

        // Draws all triangles the mesh contains
        for (const sf::Drawable *drawable : m_drawables)
            target.draw(*drawable);

        // TODO: Insert glEnd() (complimentary to glBegin(...)

        glPopMatrix();
    }

} // Namespace sf3
