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

#ifndef COLORABLE_HPP_INCLUDED
#define COLORABLE_HPP_INCLUDED

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

// Program specific:
#include "Color.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>

// System specific includes:

namespace sf3
{

    ////////////////////////////////////////////////////////////
    /// \brief Base class defining an object of different colors
    ///
    ////////////////////////////////////////////////////////////
    class Colorable
    {
    public:

        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// Sets the color to white if no argument specified
        ///
        /// \param color        The color to assign, default white
        ////////////////////////////////////////////////////////////
        Colorable(const Color &color = Color(1.f, 1.f, 1.f, 1.f));

        ////////////////////////////////////////////////////////////
        /// \brief Virtual destructor
        ///
        ////////////////////////////////////////////////////////////
        virtual ~Colorable();

        ////////////////////////////////////////////////////////////
        /// \brief Apply a single color
        ///
        /// Mostly used to color individual vertices
        ///
        /// \param color        The color to assign
        ////////////////////////////////////////////////////////////
        virtual void setColor(const sf::Color &color);

        ////////////////////////////////////////////////////////////
        /// \brief Apply a single color
        ///
        /// Mostly used to color individual vertices
        ///
        /// \param color        The color to assign
        ////////////////////////////////////////////////////////////
        virtual void setColor(const Color &color);

        ////////////////////////////////////////////////////////////
        /// \brief Return the color value
        ///
        /// Mostly used to color individual vertices
        ///
        /// \return The sf3::Color struct of the assigned color
        ////////////////////////////////////////////////////////////
        virtual const Color &getColor() const;

        ////////////////////////////////////////////////////////////
        /// \brief Apply a fill color
        ///
        /// The fill color can be applied to multi-vertex objects
        /// such as triangles and rectangles.
        ///
        /// \param color        The color to assign
        ////////////////////////////////////////////////////////////
        virtual void setFillColor(const sf::Color &color);

        ////////////////////////////////////////////////////////////
        /// \brief Apply a fill color
        ///
        /// The fill color can be applied to multi-vertex objects
        /// such as triangles and rectangles.
        ///
        /// \param color        The color to assign
        ////////////////////////////////////////////////////////////
        virtual void setFillColor(const Color &color);

        ////////////////////////////////////////////////////////////
        /// \brief Get the fill color
        ///
        /// \return The color that is assigned as fill
        ////////////////////////////////////////////////////////////
        virtual const Color &getFillColor() const;

    };

} // Namespace sf3


#endif // COLORABLE_HPP_INCLUDED
