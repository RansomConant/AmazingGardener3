#include "Tomato.h"

Tomato::Tomato() {

}

bool Tomato::load(const std::string& filename) {
    if (m_texture.loadFromFile(filename)) {
        m_filename = filename;
        m_sprite.setTexture(m_texture);
        m_valid = true;
        return true;
    }
    return false;
}

void Tomato::draw(sf::RenderWindow& window) {
    if (m_valid)
        window.draw(m_sprite);
}

void Tomato::move(sf::Vector2f loc) {
    if (m_valid)
        m_sprite.move(loc);
}

void Tomato::setPosition(float x, float y) {
    if (m_valid)
        m_sprite.setPosition(x, y);
}

sf::Vector2f Tomato::getPosition() const {
    if (m_valid)
        return m_sprite.getPosition();
    else
        return sf::Vector2f(0, 0);
}

float Tomato::getHeight() const {
    return m_sprite.getLocalBounds().height;
}

float Tomato::getWidth() const {
    return m_sprite.getLocalBounds().width;
}

void Tomato::setScale(float scale) {
    if (m_valid)
        m_sprite.setScale(scale, scale);
}

