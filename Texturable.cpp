#include "Texturable.hpp"


namespace sf3
{

    Texturable::Texturable()
    :
    m_texture(nullptr),
    m_repetition(sf::Vector2f(0.f, 0.f))
    {}


    Texturable::Texturable(sf::Texture *texture, const sf::Vector2f &repetition)
    :
    m_texture(texture),
    m_repetition(repetition)
    {}


    Texturable::~Texturable()
    {}


    void Texturable::setTexture(sf::Texture &texture)
    {
        m_texture = &texture;
    }


    void Texturable::setRepeated(const sf::Vector2f &st)
    {
        m_repetition = st;
    }


    void Texturable::setRepeated(const bool state)
    {
        if (m_texture)
            m_texture->setRepeated(state);
    }


} // Namespace sf3
