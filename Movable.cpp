#include "Movable.hpp"


namespace sf3
{

    Movable::Movable()
    :
    m_position(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Movable::Movable(const sf::Vector3f &offset)
    :
    m_position(offset)
    {}


    Movable::~Movable()
    {}


    void Movable::move(const sf::Vector3f &offset)
    {
        m_position += offset;
    }


    void Movable::setPosition(const sf::Vector3f &offset)
    {
        m_position = offset;
    }


    const sf::Vector3f &Movable::getPosition() const
    {
        return std::cref(m_position);
    }

} // Namespace sf3
