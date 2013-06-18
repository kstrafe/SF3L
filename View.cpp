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

#include "View.hpp"

namespace sf3
{

    View::View(sf::Vector3f position)
    :
    m_x_position(position.x),
    m_y_position(position.y),
    m_z_position(position.z),
    m_x_rotation(0.f),
    m_y_rotation(0.f),
    m_z_rotation(0.f)
    {}


    View::~View()
    {}


    void View::depth(float amount)
    {
        m_x_position += std::sin(m_y_rotation * (3.141592653589793238462643383f / 180.f)) * amount;
        m_z_position -= std::cos(m_y_rotation * (3.141592653589793238462643383f / 180.f)) * amount;
    }


    void View::rotate(float direction)
    {
        m_y_rotation += direction;
        m_y_rotation = static_cast<float>(static_cast<int>(m_y_rotation) % 360);
    }

} // Namespace sf3
