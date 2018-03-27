#include "AnimatedGameObject.h"
#include "SFML/Graphics.hpp"

void AnimatedGameObject::setWidth(int width) {
    w = width;
}

bool AnimatedGameObject::load(const std::string & filename)
{

    if (m_texture.loadFromFile(filename)) {
        sf::IntRect rectSourceSprite(0, 0, w, 900);
        m_sprite.setTexture(m_texture);
        m_sprite.setTextureRect(rectSourceSprite);
        m_filename = filename;
        m_valid = true;
        return true;
    }

    return false;
}

void AnimatedGameObject::draw(sf::RenderWindow & window)
{
    if (m_valid)
        window.draw(m_sprite);
}

void AnimatedGameObject::update(float deltaT)
{
    i = i + 1;
    if ((i % 100) == 0) {
        n = (n + w) % (w * 10);
        sf::IntRect rectSourceSprite(n, 0, w, 900);
        m_sprite.setTextureRect(rectSourceSprite);
    }

}

void AnimatedGameObject::setPosition(float x, float y)
{
    if (m_valid)
        m_sprite.setPosition(x, y);
}

void AnimatedGameObject::move(sf::Vector2f loc)
{
    if (m_valid) {
        if (loc.x != 0 || loc.y != 0) {
            //n = (n + w) % (w*5);
        }
        sf::IntRect rectSourceSprite(n, 0, w, 900);
        m_sprite.setTextureRect(rectSourceSprite);
        m_sprite.move(loc);
    }
}

sf::Vector2f AnimatedGameObject::getPosition() const
{
    if (m_valid)
        return m_sprite.getPosition();
    else
        return sf::Vector2f(0, 0);
}

float AnimatedGameObject::getHeight() const
{
    return m_sprite.getLocalBounds().height;
}

float AnimatedGameObject::getWidth() const
{
    return m_sprite.getLocalBounds().width;
}

void AnimatedGameObject::setScale(float scale)
{
    if (m_valid)
        m_sprite.setScale(scale, scale);
}


