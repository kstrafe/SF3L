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

#include "Rotatable.hpp"


namespace sf3
{

    ////////////////////////////////////////////////////////////
    Rotatable::Rotatable(const float angle, const sf::Vector3f &dispersion)
    :
    m_angle(angle),
    m_rotation(dispersion)
    {}

    ////////////////////////////////////////////////////////////
    Rotatable::~Rotatable()
    {}

    ////////////////////////////////////////////////////////////
    const float Rotatable::getAngle() const
    {
        return std::cref(m_angle);
    }

    ////////////////////////////////////////////////////////////
    const sf::Vector3f &Rotatable::getDispersion() const
    {
        return std::cref(m_rotation);
    }

    ////////////////////////////////////////////////////////////
    void Rotatable::setRotation(const float angle)
    {
        m_angle = angle;
        m_angle = static_cast<float>(static_cast<int>(m_angle) % 360);
    }

    ////////////////////////////////////////////////////////////
    void Rotatable::setRotation(const float angle, const sf::Vector3f &dispersion)
    {
        m_angle = angle;
        m_angle = static_cast<float>(static_cast<int>(m_angle) % 360);
        m_rotation = dispersion;
    }

    ////////////////////////////////////////////////////////////
    void Rotatable::setRotation(const sf::Vector3f &dispersion)
    {
        m_rotation = dispersion;
    }

    ////////////////////////////////////////////////////////////
    void Rotatable::rotate(const float angle)
    {
        m_angle += angle;
        m_angle = static_cast<float>(static_cast<int>(m_angle) % 360);
    }

    ////////////////////////////////////////////////////////////
    void Rotatable::rotate(const float angle, const sf::Vector3f &dispersion)
    {
        m_angle += angle;
        m_angle = static_cast<float>(static_cast<int>(m_angle) % 360);
        m_rotation += dispersion;
    }

    ////////////////////////////////////////////////////////////
    void Rotatable::rotate(const sf::Vector3f &dispersion)
    {
        m_rotation += dispersion;
    }

} // Namespace sf3
