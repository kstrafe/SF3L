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

#ifndef MESH_HPP_INCLUDED
#define MESH_HPP_INCLUDED

// Program specific:
#include "Triangle.hpp"
#include "Movable.hpp"
#include "Rotatable.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    class Mesh
    :
    public Movable,
    public Rotatable,
    public sf::Drawable
    {
    public:

        Mesh();
        Mesh(const Mesh &mesh);
        ~Mesh();

        void operator=(const Mesh &mesh);
        sf::Drawable &operator[](std::size_t pos);

        void setFillColor(sf::Color color);

        void add(sf::Drawable &drawable);
        void erase(const std::size_t pos);

    private:

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        std::vector<sf::Drawable *> m_drawables;
    };

} // Namespace sf3

#endif // MESH_HPP_INCLUDED
