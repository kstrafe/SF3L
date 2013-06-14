#include "NocolVertex.hpp"


namespace sf3
{

    NocolVertex::NocolVertex(sf::Vector3f position)
    :
    Movable(position)
    {}


    NocolVertex::NocolVertex(const NocolVertex &nocolvertex)
    :
    Movable(nocolvertex.m_position)
    {}


    void NocolVertex::operator=(const NocolVertex &nocolvertex)
    {
        m_position = nocolvertex.m_position;
    }


    NocolVertex::~NocolVertex()
    {}


    void NocolVertex::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        glPushMatrix();

        glBegin(GL_POINTS);
            glVertex3f(m_position.x, m_position.y, m_position.z);
        glEnd();

        glPopMatrix();
    }

} // Namespace sf3
