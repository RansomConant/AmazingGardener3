//
// Created by Ransom Conant` on 12/6/16.
//
#pragma once

#include "Screen.h"

class Menu : public Screen
{
public:
    //use default screen size
    Menu();
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

    bool m_enter = false;
    bool m_space = false;
    sf::Font Font;
    sf::Text Menu1;
    sf::Text Menu2;
    sf::Text Menu3;
    bool blink = false;
};


