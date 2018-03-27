//
// Created by Ransom Conant` on 12/6/16.
//
#pragma once
#include <SFML/Graphics.hpp>


class Screen {

public:
    //run the screen
    virtual int run(sf::RenderWindow &m_window, int &score, int &highscore) = 0;


private:
    virtual void processEvents(sf::RenderWindow &m_window) = 0;
    //update the screen
    virtual int update(sf::Time deltaT, int &score) = 0;
    //draw the scene
    virtual void render(sf::RenderWindow &m_window) = 0;
    //handle input from the user
    virtual void handlePlayerInput(sf::Keyboard::Key key, bool isDown) = 0;

};

