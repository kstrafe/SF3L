#ifndef MOVABLE_HPP_INCLUDED
#define MOVABLE_HPP_INCLUDED

// Program specific:

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>

// System specific includes:

namespace sf3
{

    class Movable
    {
    public:

        Movable();
        Movable(const sf::Vector3f &offset);
        virtual ~Movable();

        void move(const sf::Vector3f &offset);
        void setPosition(const sf::Vector3f &offset);
        const sf::Vector3f &getPosition() const;

    protected:

        sf::Vector3f m_position;
    };

} // Namespace sf3

#endif // MOVABLE_HPP_INCLUDED
