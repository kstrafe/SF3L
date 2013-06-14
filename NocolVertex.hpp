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
