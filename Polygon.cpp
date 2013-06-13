#include "Polygon.hpp"


namespace sf3
{

    Polygon::Polygon()
    :
    m_position(sf::Vector3f(0.f, 0.f, 0.f)),
    m_angle(0.f),
    m_rotation(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Polygon::Polygon(const Polygon &polygon)
    :
    m_position(polygon.m_position),
    m_angle(polygon.m_angle),
    m_rotation(polygon.m_rotation)
    {}


    Polygon::~Polygon()
    {}


    void Polygon::operator=(const Polygon &polygon)
    {
        m_position = polygon.m_position;
        m_angle = polygon.m_angle;
        m_rotation = polygon.m_rotation;
    }


    Vertex &Polygon::operator[](std::size_t pos)
    {
        return std::ref(vertices[pos]);
    }


    void Polygon::setPosition(sf::Vector3f position)
    {
        m_position = position;
    }


    const sf::Vector3f &Polygon::getPosition() const
    {
        return std::ref(m_position);
    }


    void Polygon::setFillColor(sf::Color color)
    {
        for (Vertex &vert : vertices)
            vert.setColor(color);
    }


    void Polygon::setFillColor(Color color)
    {
        for (Vertex &vert : vertices)
            vert.setColor(color);
    }


    const Color &Polygon::getFillColor() const
    {
        return std::cref(vertices[0].getColor());
    }


    // PRIVATE:


    void Polygon::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        // Transformations to all vertices
        glTranslatef(m_position.x, m_position.y, m_position.z);
        glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);

        glBegin(GL_POLYGON);
        for (const Vertex &vert : vertices)
        {
            glColor3f(vert.m_color.r, vert.m_color.g, vert.m_color.b);
            glVertex3f(vert.m_position.x, vert.m_position.y, vert.m_position.z);
        }
        glEnd();

        glPopMatrix();
    }

} // Namespace sf3
