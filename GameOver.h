//
// Created by Ransom Conant` on 12/6/16.
//
#pragma once


#include "Screen.h"

class GameOver : public Screen
{
public:
    //use default screen size
    GameOver();
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

    bool m_esc = false;
    bool m_enter = false;
    sf::Font Font;
    sf::Text dead;
    sf::Text cont;
    sf::Text highscore;
    sf::Text newhighscore;
    sf::Text yourscore;
    sf::Text menu;

    bool newhs = false;

    bool blink = false;
};

