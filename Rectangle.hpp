#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

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

    class Rectangle : public sf::Drawable
    {
    public:

        Rectangle();
        Rectangle(const Rectangle &rectangle);
        ~Rectangle();

        void operator=(const Rectangle &rectangle);
        Vertex &operator[](std::size_t pos);

        void setPosition(sf::Vector3f position);
        void setFillColor(sf::Color color);

        void setTexture(sf::Texture &texture);
        void setRepeated(sf::Vector2f st);
        void setRepeated(bool state = true);

        void setRotation(float angle);
        void setRotation(float angle, sf::Vector3f dispersion);
        void setRotation(sf::Vector3f dispersion);

        void rotate(float angle);
        void rotate(float angle, sf::Vector3f dispersion);
        void rotate(sf::Vector3f dispersion);


    private:

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        Vertex m_vertices[4];
        sf::Vector3f m_position;

        sf::Texture *m_texture;
        sf::Vector2f repetition;

        float m_angle;
        sf::Vector3f m_rotation;

    };

} // Namespace sf3

#endif // RECTANGLE_HPP_INCLUDED
