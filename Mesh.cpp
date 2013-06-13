#include "Mesh.hpp"

namespace sf3
{

    Mesh::Mesh()
    :
    m_position(sf::Vector3f(0.f, 0.f, 0.f)),
    m_rotation_angle(0.f),
    m_rotation(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Mesh::Mesh(const Mesh &mesh)
    :
    m_triangles(mesh.m_triangles),
    m_position(mesh.m_position),
    m_rotation_angle(0.f),
    m_rotation(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Mesh::~Mesh()
    {}


    void Mesh::operator=(const Mesh &mesh)
    {
        m_triangles = mesh.m_triangles;
        m_position = mesh.m_position;
        m_rotation_angle = mesh.m_rotation_angle;
        m_rotation = mesh.m_rotation;
    }


    Triangle &Mesh::operator[](std::size_t pos)
    {
        return std::ref(m_triangles[pos]);
    }


    void Mesh::setPosition(sf::Vector3f position)
    {
        m_position = position;
    }


    sf::Vector3f Mesh::getPosition()
    {
        return m_position;
    }


    void Mesh::move(sf::Vector3f movement)
    {
        m_position += movement;
    }


    void Mesh::rotate(float angle)
    {
        m_rotation_angle += angle;
    }


    void Mesh::rotate(float angle, sf::Vector3f dispersion)
    {
        m_rotation_angle += angle;
        m_rotation += dispersion;
    }


    void Mesh::setRotation(float angle)
    {
        m_rotation_angle = angle;
    }


    void Mesh::setRotation(float angle, sf::Vector3f dispersion)
    {
        m_rotation_angle = angle;
        m_rotation = dispersion;
    }


    void Mesh::setFillColor(sf::Color color)
    {
        for (Triangle &triangle : m_triangles)
        {
            triangle.setFillColor(color);
        }
    }


    void Mesh::add(const Triangle &triangle)
    {
        m_triangles.push_back(triangle);
    }


    void Mesh::erase(const std::size_t pos)
    {
        m_triangles.erase(m_triangles.begin() + pos);
    }


    void Mesh::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        // Apply mesh's own transformations
        glTranslatef(m_position.x, m_position.y, m_position.z);
        glRotatef(m_rotation_angle, m_rotation.x, m_rotation.y, m_rotation.z);

        // TODO: Insert glBegin(GL_TRIANGLES) here to increase draw speed.

        // Draws all triangles the mesh contains
        for (const Triangle &triangle : m_triangles)
            target.draw(triangle);

        // TODO: Insert glEnd() (complimentary to glBegin(...)

        glPopMatrix();
    }

} // Namespace sf3
