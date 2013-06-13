#ifndef MESH_HPP_INCLUDED
#define MESH_HPP_INCLUDED

// Program specific:
#include "Triangle.hpp"

// Utilities:

// Standard Library components:

// External libraries:
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// System specific includes:

namespace sf3
{

    class Mesh : public sf::Drawable
    {
    public:

        Mesh();
        Mesh(const Mesh &mesh);
        ~Mesh();

        void operator=(const Mesh &triangle);
        Triangle &operator[](std::size_t pos);

        void setPosition(sf::Vector3f position);
        sf::Vector3f getPosition();

        void move(sf::Vector3f movement);
        void rotate(float angle);
        void rotate(float angle, sf::Vector3f dispersion);
        void setRotation(float angle);
        void setRotation(float angle, sf::Vector3f dispersion);

        void setFillColor(sf::Color color);

        void add(const Triangle &triangle);
        void erase(const std::size_t pos);

    private:

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        std::vector<Triangle> m_triangles;
        sf::Vector3f m_position;

        float m_rotation_angle;
        sf::Vector3f m_rotation;
    };

} // Namespace sf3

#endif // MESH_HPP_INCLUDED
