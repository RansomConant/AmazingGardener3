#include "Gardener.h"
#include "SFML/Graphics.hpp"

void Gardener::setWidth(int width) {
    w = width;
}

int Gardener::getDirection() {
    return dir;
}

void Gardener::setHeight(int height) {
    h = height;
}

void Gardener::setDirection(int direction) {
    dir = direction;
}

void Gardener::setStartCol(int sc) {
    startcol = sc;
}

bool Gardener::load(const std::string & filename)
{

    if (m_texture.loadFromFile(filename)) {
        sf::IntRect rectSourceSprite(startcol, 0, w, h);
        m_sprite.setTexture(m_texture);
        m_sprite.setTextureRect(rectSourceSprite);
        m_filename = filename;
        m_valid = true;
        return true;
    }

    return false;
}

void Gardener::draw(sf::RenderWindow & window)
{
    if (m_valid)
        window.draw(m_sprite);
}

void Gardener::update(float deltaT)
{
    i = i + 1;
    if ((i % 100) == 0) {
        n = (n + h) % (h*3);
        sf::IntRect rectSourceSprite(startcol, n, w, h);
        m_sprite.setTextureRect(rectSourceSprite);
    }
    //move in correct direction every update**********

}

void Gardener::setPosition(float x, float y)
{
    if (m_valid)
        m_sprite.setPosition(x, y);
}

void Gardener::move(sf::Vector2f loc)
{
    if (m_valid) {
        if (loc.x != 0 || loc.y != 0) {
            //n = (n + w) % (w*5);
        }
        sf::IntRect rectSourceSprite(startcol, n, w, h);
        m_sprite.setTextureRect(rectSourceSprite);
        m_sprite.move(loc);
    }
}

sf::Vector2f Gardener::getPosition() const
{
    if (m_valid)
        return m_sprite.getPosition();
    else
        return sf::Vector2f(0, 0);
}

float Gardener::getHeight() const
{
    return m_sprite.getLocalBounds().height;
}

float Gardener::getWidth() const
{
    return m_sprite.getLocalBounds().width;
}

void Gardener::setScale(float scale)
{
    if (m_valid)
        m_sprite.setScale(scale, scale);
}



