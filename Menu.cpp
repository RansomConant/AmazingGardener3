//
// Created by Ransom Conant` on 12/6/16.
//
#include <iostream>
#include "Menu.h"

Menu::Menu()
{
    Font.loadFromFile("ARCADECLASSIC.TTF");


    Menu1.setFont(Font);
    Menu1.setCharacterSize(50);
    Menu1.setString("AMAZING GARDENER 3");
    Menu1.setPosition({80, 120});

    Menu2.setFont(Font);
    Menu2.setCharacterSize(20);
    Menu2.setFillColor(sf::Color::Red);
    Menu2.setString("PRESS   ENTER   TO   PLAY");
    Menu2.setPosition({ 200, 240 });

    Menu3.setFont(Font);
    Menu3.setCharacterSize(20);
    Menu3.setFillColor(sf::Color::Cyan);
    Menu3.setString("PRESS   SPACE   TO   READ   LEARN    ABOUT   GARTH   THE   GARDENER");
    Menu3.setPosition(30, 450);


}

int Menu::run(sf::RenderWindow &m_window, int &score, int &hscore) {
    sf::Clock clock;
    while(m_window.isOpen()) {

        sf::Time deltaT = clock.getElapsedTime();


        processEvents(m_window);
        update(deltaT, score);
        render(m_window);

        if (deltaT.asSeconds() > .9f){
            clock.restart();
        }
        if (m_space){
            m_space = false;
            return 1;
        }
        if (m_enter){
            m_enter = false;
            return 2;
        }
    }
    return (-1);
}


void Menu::processEvents(sf::RenderWindow &m_window) {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
                //handle key down here
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void Menu::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if(key == sf::Keyboard::Return)
        m_enter = isDown;
    if (key == sf::Keyboard::Space)
        m_space = isDown;
}

int Menu::update(sf::Time deltaT, int &score){
    if (deltaT.asSeconds() > .9f){
        if (blink) {
            Menu2.setFillColor(sf::Color::Red);
            blink = false;
        }
        else {
            Menu2.setFillColor(sf::Color::Yellow);
            blink = true;
        }

    }
    return 0;

}

void Menu::render(sf::RenderWindow &m_window){
    m_window.clear();

    m_window.draw(Menu1);
    m_window.draw(Menu2);
    m_window.draw(Menu3);

    m_window.display();
}