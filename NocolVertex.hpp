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

#ifndef NOCOLVERTEX_HPP_INCLUDED
#define NOCOLVERTEX_HPP_INCLUDED

// Program specific:
#include "Movable.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:


namespace sf3
{

    class NocolVertex
    :
    public Movable,
    public sf::Drawable
    {
    public:

        NocolVertex(sf::Vector3f position = sf::Vector3f(0.f, 0.f, 0.f));
        NocolVertex(const NocolVertex &nocolvertex);
        void operator=(const NocolVertex &nocolvertex);
        ~NocolVertex();

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    };

} // Namespace sf3


#endif // NOCOLVERTEX_HPP_INCLUDED
