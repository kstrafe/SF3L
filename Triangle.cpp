#include "Triangle.hpp"

namespace sf3
{

    Triangle::Triangle()
    :
    m_position(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Triangle::Triangle(const Triangle &triangle)
    :
    m_vertices(triangle.m_vertices),
    m_position(triangle.m_position)
    {}


    Triangle::~Triangle()
    {}


    void Triangle::operator=(const Triangle &triangle)
    {
        m_vertices[0] = triangle.m_vertices[0];
        m_vertices[1] = triangle.m_vertices[1];
        m_vertices[2] = triangle.m_vertices[2];
        m_position = triangle.m_position;
    }


    Vertex &Triangle::operator[](std::size_t pos)
    {
        return std::ref(m_vertices[pos]);
    }


    void Triangle::setPosition(sf::Vector3f position)
    {
        m_position = position;
    }


    void Triangle::setFillColor(sf::Color color)
    {
        m_vertices[0].setColor(color);
        m_vertices[1].setColor(color);
        m_vertices[2].setColor(color);
    }


    void Triangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();
        glTranslatef(m_position.x, m_position.y, m_position.z);

        glBegin(GL_TRIANGLES);
            glColor3f(m_vertices[0].m_color.r, m_vertices[0].m_color.g, m_vertices[0].m_color.b);
            glVertex3f(m_vertices[0].m_position.x, m_vertices[0].m_position.y, m_vertices[0].m_position.z);

            glColor3f(m_vertices[1].m_color.r, m_vertices[1].m_color.g, m_vertices[1].m_color.b);
            glVertex3f(m_vertices[1].m_position.x, m_vertices[1].m_position.y, m_vertices[1].m_position.z);

            glColor3f(m_vertices[2].m_color.r, m_vertices[2].m_color.g, m_vertices[2].m_color.b);
            glVertex3f(m_vertices[2].m_position.x, m_vertices[2].m_position.y, m_vertices[2].m_position.z);
        glEnd();

        glPopMatrix();
    }

} // Namespace sf3
