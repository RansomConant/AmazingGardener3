#include "Bug.h"
#include "SFML/Graphics.hpp"

void Bug::setWidth(int width) {
    w = width;
}

void Bug::setJ(int jin) {
    j = jin;
}

void Bug::setHeight(int height) {
    h = height;
}

void Bug::setDirection(int direction) {
    dir = direction;
}

void Bug::setStartRow(int rc) {
    startrow = rc;
}
bool Bug::load(const std::string & filename)
{

    if (m_texture.loadFromFile(filename)) {
        sf::IntRect rectSourceSprite(0, startrow, w, h);
        m_sprite.setTexture(m_texture);
        m_sprite.setTextureRect(rectSourceSprite);
        m_filename = filename;
        m_valid = true;
        return true;
    }

    return false;
}

void Bug::draw(sf::RenderWindow & window)
{
    if (m_valid)
        window.draw(m_sprite);
}

void Bug::update(float deltaT)
{
    i = i + 1;
    if ((i % 100) == 0) {
        n = (n + w) % (w * 3);
        sf::IntRect rectSourceSprite(n, startrow, w, h);
        m_sprite.setTextureRect(rectSourceSprite);
    }
    if ((i % 20) == 0) {
        j = j + 1;
        if ((j > 0)&(j <= 550)) {
            startx -= 1;
            startrow = 64;
        }
        if ((j > 550)&(j <= 650)) {
            starty -= 1;
            startrow = 192;
        }
        if ((j > 650)&(j <= 1200)) {
            startx += 1;
            startrow = 128;
        }
        if ((j > 1200)&(j < 1300)) {
            starty += 1;
            startrow = 0;
        }
        if (j == 1300) {
            j = 0;
        }
        this->setPosition(startx, starty);
    }
}

void Bug::setPosition(float x, float y)
{
    if (m_valid)
        m_sprite.setPosition(x, y);
    startx = x;
    starty = y;
}

void Bug::move(sf::Vector2f loc)
{
    if (m_valid) {
        if (loc.x != 0 || loc.y != 0) {
            //n = (n + w) % (w*5);
        }
        sf::IntRect rectSourceSprite(n, startrow, w, h);
        m_sprite.setTextureRect(rectSourceSprite);
        m_sprite.move(loc);
    }
}

sf::Vector2f Bug::getPosition() const
{
    if (m_valid)
        return m_sprite.getPosition();
    else
        return sf::Vector2f(0, 0);
}

float Bug::getHeight() const
{
    return m_sprite.getLocalBounds().height;
}

float Bug::getWidth() const
{
    return m_sprite.getLocalBounds().width;
}

void Bug::setScale(float scale)
{
    if (m_valid)
        m_sprite.setScale(scale, scale);
}


