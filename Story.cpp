//
// Created by Ransom Conant` on 12/13/16.
//

#include "Story.h"


Story::Story()
{


}

int Story::run(sf::RenderWindow &m_window, int &score, int &hscore) {

    m_story.load("Story.png");
    m_story.setScale(.48f);
    m_story.setPosition(0,480);
    sf::Clock clock;
    sf::Clock clock2;
    while(m_window.isOpen()) {


        sf::Time deltaT = clock.restart();

        sf::Time dT = clock2.getElapsedTime();
        if (dT.asSeconds() > 19.5) {
            deltaT *= 0.0f;
            Menu2.setFont(Font);
            Menu2.setCharacterSize(20);
            Menu2.setFillColor(sf::Color::Red);
            Menu2.setString("PRESS   ENTER   TO   RETURN   TO   MENU");
            Menu2.setPosition({ 100, 460 });
        }

        processEvents(m_window);
        update(deltaT, score);
        render(m_window);

        if (m_enter && dT.asSeconds() > 19) {
            m_enter = false;
            return 0;
        }

    }
    return (-1);
}

void Story::processEvents(sf::RenderWindow &m_window) {
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

void Story::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if(key == sf::Keyboard::Up)
        m_up = isDown;
    if(key == sf::Keyboard::Down)
        m_down = isDown;
    if(key == sf::Keyboard::Return)
        m_enter = isDown;
}

//use time since last update to get smooth movement
int Story::update(sf::Time deltaT, int &score) {
    //Look a vector class!
    sf::Vector2f movement(0.0f, 0.0f);

    movement.y -= m_speed;


    m_story.move(movement * deltaT.asSeconds());
    return 0;
}

void Story::render(sf::RenderWindow &m_window) {
    m_window.clear();

    m_window.draw(Menu2);
    m_story.draw(m_window);

    m_window.display();
}
