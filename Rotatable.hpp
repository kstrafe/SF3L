#ifndef ROTATABLE_HPP_INCLUDED
#define ROTATABLE_HPP_INCLUDED

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

    class Rotatable
    {
    public:

        Rotatable();
        Rotatable(const float angle, const sf::Vector3f &dispersion);
        virtual ~Rotatable();

        const float &getAngle() const;
        const sf::Vector3f &getDispersion() const;

        void setRotation(const float angle);
        void setRotation(const float angle, const sf::Vector3f &dispersion);
        void setRotation(const sf::Vector3f &dispersion);

        void rotate(const float angle);
        void rotate(const float angle, const sf::Vector3f &dispersion);
        void rotate(const sf::Vector3f &dispersion);

    protected:

        float m_angle;
        sf::Vector3f m_rotation;
    };

} // Namespace sf3

#endif // ROTATABLE_HPP_INCLUDED
