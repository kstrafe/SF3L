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

#ifndef ROTATABLE_HPP_INCLUDED
#define ROTATABLE_HPP_INCLUDED

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

// Program specific:
#include "Vertex.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    ////////////////////////////////////////////////////////////
    /// \brief Base class defining a rotatable object
    ///
    ////////////////////////////////////////////////////////////
    class Rotatable
    {
    public:

        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        ////////////////////////////////////////////////////////////
        Rotatable(const float angle = 0.f, const sf::Vector3f &dispersion = sf::Vector3f(0.f, 0.f, 0.f));

        ////////////////////////////////////////////////////////////
        /// \brief Default virtual destructor
        ///
        ////////////////////////////////////////////////////////////
        virtual ~Rotatable();

        ////////////////////////////////////////////////////////////
        /// \brief Return the angle
        ///
        /// \return The angle value
        ////////////////////////////////////////////////////////////
        virtual const float getAngle() const;

        ////////////////////////////////////////////////////////////
        /// \brief Return the dispersion of the angle
        ///
        /// \return an sf::Vector3f of rotation
        ////////////////////////////////////////////////////////////
        virtual const sf::Vector3f &getDispersion() const;

        ////////////////////////////////////////////////////////////
        /// \brief Set the angle of rotation
        ///
        /// \param angle        value in range [0.0, 360.0>
        ////////////////////////////////////////////////////////////
        virtual void setRotation(const float angle);

        ////////////////////////////////////////////////////////////
        /// \brief Set the angle of rotation
        ///
        /// \param angle        value in range [0.0, 360.0>
        /// \param dispersion   rotation vector
        ////////////////////////////////////////////////////////////
        virtual void setRotation(const float angle, const sf::Vector3f &dispersion);

        ////////////////////////////////////////////////////////////
        /// \brief Set the angle of rotation
        ///
        /// \param dispersion   rotation vector
        ////////////////////////////////////////////////////////////
        virtual void setRotation(const sf::Vector3f &dispersion);

        ////////////////////////////////////////////////////////////
        /// \brief Increase the angle of rotation
        ///
        /// \param angle        value in range [0.0, 360.0>
        ////////////////////////////////////////////////////////////
        virtual void rotate(const float angle);

        ////////////////////////////////////////////////////////////
        /// \brief Increase the angle of rotation
        ///
        /// \param angle        value in range [0.0, 360.0>
        /// \param dispersion   rotation vector
        ////////////////////////////////////////////////////////////
        virtual void rotate(const float angle, const sf::Vector3f &dispersion);

        ////////////////////////////////////////////////////////////
        /// \brief Increase the angle of rotation
        ///
        /// \param dispersion   rotation vector
        ////////////////////////////////////////////////////////////
        virtual void rotate(const sf::Vector3f &dispersion);

    protected:

        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        float m_angle; ///< angle of rotation
        sf::Vector3f m_rotation; ///< vector of rotation
    };

} // Namespace sf3

#endif // ROTATABLE_HPP_INCLUDED
