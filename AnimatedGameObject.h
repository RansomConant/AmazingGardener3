#pragma once
#include "GameObject.h"

class AnimatedGameObject : public GameObject {
public:
    // Inherited via GameObject
    void setWidth(int width);
    bool load(const std::string & filename) override;
    void draw(sf::RenderWindow & window) override;
    void update(float deltaT) override;
    void setPosition(float x, float y) override;
    void move(sf::Vector2f) override;
    sf::Vector2f getPosition() const override;
    float getHeight() const override;
    float getWidth() const override;
    void setScale(float scale) override;
private:
    int w = 0;
    int n = 0;
    int i = 0;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    bool m_valid = false;
};

