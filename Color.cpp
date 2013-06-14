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

#include "Color.hpp"


namespace sf3
{

    Color::Color()
    :
    r(1.f),
    g(1.f),
    b(1.f),
    a(1.f)
    {}


    Color::Color(const float red, const float green, const float blue, const float alpha)
    :
    r(red),
    g(green),
    b(blue),
    a(alpha)
    {}


    Color::Color(const sf::Color &color)
    :
    r(color.r / 255.f),
    g(color.g / 255.f),
    b(color.b / 255.f),
    a(color.a / 255.f)
    {}


    Color::Color(const Color &color)
    :
    r(color.r),
    g(color.g),
    b(color.b),
    a(color.a)
    {}


    Color::~Color()
    {}


    void Color::operator=(const sf::Color &color)
    {
        r = static_cast<float>(color.r) / 255.f;
        g = static_cast<float>(color.g) / 255.f;
        b = static_cast<float>(color.b) / 255.f;
        a = static_cast<float>(color.a) / 255.f;
    }


    void Color::operator=(const Color &color)
    {
        r = color.r;
        g = color.g;
        b = color.b;
        a = color.a;
    }

} // Namespace sf3
