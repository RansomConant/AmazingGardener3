//
// Created by Ransom Conant` on 12/13/16.
//
#pragma once

#include "Screen.h"
#include "RegularGameObject.h"
#include <SFML/Graphics.hpp>

class Story : public Screen
{
public:
    //use default screen size
    Story();
    //run the game
    int run(sf::RenderWindow &m_window, int &score, int &hscore);

private:
    void processEvents(sf::RenderWindow &m_window);
    //update the game objects
    int update(sf::Time deltaT, int &score);
    //draw the scene
    void render(sf::RenderWindow &m_window);
    //handle input from the user
    void handlePlayerInput(sf::Keyboard::Key key, bool isDown);

    RegularGameObject m_story;
    sf::Text Menu2;
    sf::Font Font;



    float m_speed = 25.0f;
    bool m_up = false;
    bool m_down = false;
    bool m_enter = false;


};