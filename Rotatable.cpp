#include "Rotatable.hpp"


namespace sf3
{

    Rotatable::Rotatable()
    :
    m_angle(0.f),
    m_rotation(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Rotatable::Rotatable(const float angle, const sf::Vector3f &dispersion)
    :
    m_angle(0.f),
    m_rotation(sf::Vector3f(0.f, 0.f, 0.f))
    {}


    Rotatable::~Rotatable()
    {}


    const float &Rotatable::getAngle() const
    {
        return std::cref(m_angle);
    }


    const sf::Vector3f &Rotatable::getDispersion() const
    {
        return std::cref(m_rotation);
    }


    void Rotatable::setRotation(const float angle)
    {
        m_angle = angle;
    }


    void Rotatable::setRotation(const float angle, const sf::Vector3f &dispersion)
    {
        m_angle = angle;
        m_rotation = dispersion;
    }


    void Rotatable::setRotation(const sf::Vector3f &dispersion)
    {
        m_rotation = dispersion;
    }


    void Rotatable::rotate(const float angle)
    {
        m_angle += angle;
    }


    void Rotatable::rotate(const float angle, const sf::Vector3f &dispersion)
    {
        m_angle += angle;
        m_rotation += dispersion;
    }


    void Rotatable::rotate(const sf::Vector3f &dispersion)
    {
        m_rotation += dispersion;
    }

} // Namespace sf3
