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

#include "Texturable.hpp"


namespace sf3
{

    Texturable::Texturable()
    :
    m_texture(nullptr),
    m_repetition(sf::Vector2f(0.f, 0.f))
    {}


    Texturable::Texturable(sf::Texture *texture, const sf::Vector2f &repetition)
    :
    m_texture(texture),
    m_repetition(repetition)
    {}


    Texturable::~Texturable()
    {}


    void Texturable::setTexture(sf::Texture &texture)
    {
        m_texture = &texture;
    }


    void Texturable::setRepeated(const sf::Vector2f &st)
    {
        m_repetition = st;
    }


    void Texturable::setRepeated(const bool state)
    {
        if (m_texture)
            m_texture->setRepeated(state);
    }


} // Namespace sf3
