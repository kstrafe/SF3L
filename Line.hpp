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

#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

// Program specific:
#include "Movable.hpp"
#include "Rotatable.hpp"
#include "Colorable.hpp"
#include "Color.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    class Line
    :
    public Movable,
    public Rotatable,
    public Colorable,
    public sf::Drawable
    {
    public:

        Line();
        ~Line();

        ////////////////////////////////////////////////////////////
        /// \see Movable::move
        ////////////////////////////////////////////////////////////
        virtual void move(const sf::Vector3f &offset) final override;

        ////////////////////////////////////////////////////////////
        /// \see Movable::setPosition
        ////////////////////////////////////////////////////////////
        virtual void setPosition(const sf::Vector3f &value) final override;

        ////////////////////////////////////////////////////////////
        /// \see Movable::getPosition
        ////////////////////////////////////////////////////////////
        virtual const sf::Vector3f &getPosition() const final override;

        ////////////////////////////////////////////////////////////
        /// \see Colorable::setFillColor
        ////////////////////////////////////////////////////////////
        virtual void setFillColor(const sf::Color &color) final override;

        ////////////////////////////////////////////////////////////
        /// \see Colorable::setFillColor
        ////////////////////////////////////////////////////////////
        virtual void setFillColor(const Color &color) final override;

        ////////////////////////////////////////////////////////////
        /// \see Colorable::getFillColor
        ////////////////////////////////////////////////////////////
        virtual const Color &getFillColor() const final override;

        ////////////////////////////////////////////////////////////
        /// \see Rotatable::setRotation
        ////////////////////////////////////////////////////////////
        virtual void setRotation(const float angle) final override;

        ////////////////////////////////////////////////////////////
        /// \see Rotatable::setRotation
        ////////////////////////////////////////////////////////////
        virtual void setRotation(const float angle, const sf::Vector3f &dispersion) final override;

        ////////////////////////////////////////////////////////////
        /// \see Rotatable::setRotation
        ////////////////////////////////////////////////////////////
        virtual void setRotation(const sf::Vector3f &dispersion) final override;

        ////////////////////////////////////////////////////////////
        /// \see Rotatable::rotate
        ////////////////////////////////////////////////////////////
        virtual void rotate(const float angle) final override;

        ////////////////////////////////////////////////////////////
        /// \see Rotatable::rotate
        ////////////////////////////////////////////////////////////
        virtual void rotate(const float angle, const sf::Vector3f &dispersion) final override;

        ////////////////////////////////////////////////////////////
        /// \see Rotatable::rotate
        ////////////////////////////////////////////////////////////
        virtual void rotate(const sf::Vector3f &dispersion) final override;

        void setPointAColor(const Color &color);
        void setPointBColor(const Color &color);

        void setPointAPosition(const sf::Vector3f &value);
        void setPointBPosition(const sf::Vector3f &value);


        void setLineWidth(float width);
        const float getLineWidth() const;


    private:

        ////////////////////////////////////////////////////////////
        /// \see Vertex::draw
        ////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final override;

        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        sf::Vector3f m_point[2]; ///< Positions of both points in model space
        Color m_color[2]; ///< Colors for both points
        GLuint m_displist; ///< Amount of display lists
        GLfloat m_width; ///< Width of the line

        static constexpr std::size_t cm_display_list_amount = 8;
        static constexpr GLuint
            cm_begin_end_wrap = 0,
            cm_line_width = 1,
            cm_color_1 = 2,
            cm_position_1 = 3,
            cm_color_2 = 4,
            cm_position_2 = 5,
            cm_translation = 6,
            cm_rotation = 7;

    };

} // Namespace sf3


#endif // LINE_HPP_INCLUDED
