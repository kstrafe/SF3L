#ifndef NORMALABLE_HPP_INCLUDED
#define NORMALABLE_HPP_INCLUDED

// Program specific:

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>

// System specific includes:


namespace sf3
{

    class Normalizable
    {
    public:

        Normalizable();
        ~Normalizable();

        virtual void computeNormal() = 0;

    protected:

        sf::Vector3f m_normal;
    };

} // Namespace sf3


#endif // NORMALABLE_HPP_INCLUDED
