#include "Rectangle.hpp"

namespace sf3
{

    Rectangle::Rectangle()
    :
    m_position(sf::Vector3f(0.f, 0.f, 0.f)),
    m_texture(nullptr)
    {}


    Rectangle::Rectangle(const Rectangle &rectangle)
    :
    m_vertices(rectangle.m_vertices),
    m_position(rectangle.m_position),
    m_texture(rectangle.m_texture)
    {}


    Rectangle::~Rectangle()
    {}


    void Rectangle::operator=(const Rectangle &rectangle)
    {
        m_vertices[0] = rectangle.m_vertices[0];
        m_vertices[1] = rectangle.m_vertices[1];
        m_vertices[2] = rectangle.m_vertices[2];
        m_position = rectangle.m_position;
        m_texture = rectangle.m_texture;
    }


    Vertex &Rectangle::operator[](std::size_t pos)
    {
        return std::ref(m_vertices[pos]);
    }


    void Rectangle::setPosition(sf::Vector3f position)
    {
        m_position = position;
    }


    void Rectangle::setFillColor(sf::Color color)
    {
        m_vertices[0].setColor(color);
        m_vertices[1].setColor(color);
        m_vertices[2].setColor(color);
        m_vertices[3].setColor(color);
    }


    void Rectangle::setTexture(sf::Texture &texture)
    {
        m_texture = &texture;
    }


    void Rectangle::setRepeated(sf::Vector2f st)
    {
        repetition = st;
    }


    void Rectangle::setRepeated(bool state)
    {
        if (m_texture)
            m_texture->setRepeated(state);
    }


    void Rectangle::setRotation(float angle)
    {
        m_angle = angle;
    }


    void Rectangle::setRotation(float angle, sf::Vector3f dispersion)
    {
        m_angle = angle;
        m_rotation = dispersion;
    }


    void Rectangle::setRotation(sf::Vector3f dispersion)
    {
        m_rotation = dispersion;
    }


    void Rectangle::rotate(float angle)
    {
        m_angle += angle;
    }


    void Rectangle::rotate(float angle, sf::Vector3f dispersion)
    {
        m_angle += angle;
        m_rotation += dispersion;
    }


    void Rectangle::rotate(sf::Vector3f dispersion)
    {
        m_rotation += dispersion;
    }


    void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        glTranslatef(m_position.x, m_position.y, m_position.z);
        glRotatef(m_angle, m_rotation.x, m_rotation.y, m_rotation.z);
        sf::Texture::bind(m_texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        if (m_texture && m_texture->isRepeated())
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            glBegin(GL_QUADS);
                glTexCoord2d(0.f, 0.f);
                glColor3f(m_vertices[0].m_color.r, m_vertices[0].m_color.g, m_vertices[0].m_color.b);
                glVertex3f(m_vertices[0].m_position.x, m_vertices[0].m_position.y, m_vertices[0].m_position.z);

                glTexCoord2d(repetition.x, 0.f);
                glColor3f(m_vertices[1].m_color.r, m_vertices[1].m_color.g, m_vertices[1].m_color.b);
                glVertex3f(m_vertices[1].m_position.x, m_vertices[1].m_position.y, m_vertices[1].m_position.z);

                glTexCoord2d(repetition.x, repetition.y);
                glColor3f(m_vertices[2].m_color.r, m_vertices[2].m_color.g, m_vertices[2].m_color.b);
                glVertex3f(m_vertices[2].m_position.x, m_vertices[2].m_position.y, m_vertices[2].m_position.z);

                glTexCoord2d(0.f, repetition.y);
                glColor3f(m_vertices[3].m_color.r, m_vertices[3].m_color.g, m_vertices[3].m_color.b);
                glVertex3f(m_vertices[3].m_position.x, m_vertices[3].m_position.y, m_vertices[3].m_position.z);
            glEnd();

        }

        // when texture area is small, bilinear filter the closest mipmap

        // when texture area is large, bilinear filter the first mipmap
    //    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        else
        {
            glBegin(GL_QUADS);
                glTexCoord2d(0.f, 0.f);
                glColor3f(m_vertices[0].m_color.r, m_vertices[0].m_color.g, m_vertices[0].m_color.b);
                glVertex3f(m_vertices[0].m_position.x, m_vertices[0].m_position.y, m_vertices[0].m_position.z);

                glTexCoord2d(1.f, 0.f);
                glColor3f(m_vertices[1].m_color.r, m_vertices[1].m_color.g, m_vertices[1].m_color.b);
                glVertex3f(m_vertices[1].m_position.x, m_vertices[1].m_position.y, m_vertices[1].m_position.z);

                glTexCoord2d(1.f, 1.f);
                glColor3f(m_vertices[2].m_color.r, m_vertices[2].m_color.g, m_vertices[2].m_color.b);
                glVertex3f(m_vertices[2].m_position.x, m_vertices[2].m_position.y, m_vertices[2].m_position.z);

                glTexCoord2d(0.f, 1.f);
                glColor3f(m_vertices[3].m_color.r, m_vertices[3].m_color.g, m_vertices[3].m_color.b);
                glVertex3f(m_vertices[3].m_position.x, m_vertices[3].m_position.y, m_vertices[3].m_position.z);
            glEnd();
        }
        glPopMatrix();
    }

} // Namespace sf3
