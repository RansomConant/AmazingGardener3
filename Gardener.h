#pragma once
#include "AnimatedGameObject.h"

class Gardener : public AnimatedGameObject {
public:
    // Inherited via AnimatedGameObject
    void setWidth(int width);
    void setHeight(int height);
    int getDirection();
    void setDirection(int direction);
    void setStartCol(int sc);
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
    int h = 0;
    int i = 0;
    int n = 0;
    //direction of gardener (same as column number in sprite sheet):
    //0->down
    //1->left
    //2->right
    //3->up
    int dir = 0;
    //starting pixel for each col (0,100,200,300)
    int startcol = 0;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    bool m_valid = false;
};


