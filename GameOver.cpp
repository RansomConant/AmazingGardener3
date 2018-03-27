//
// Created by Ransom Conant` on 12/6/16.
//

#include "GameOver.h"
#include <iostream>

GameOver::GameOver() //: m_window(sf::VideoMode(640, 480), "Cool Game")
{
    Font.loadFromFile("ARCADECLASSIC.TTF");
    cont.setFont(Font);
    cont.setCharacterSize(20);
    cont.setFillColor(sf::Color::Red);
    cont.setString("PRESS   ENTER   TO   PLAY   AGAIN");
    cont.setPosition({ 175, 400 });


    dead.setFont(Font);
    dead.setCharacterSize(50);
    dead.setString("YOU   DIED");
    dead.setPosition({210, 20});

    newhighscore.setFont(Font);
    newhighscore.setCharacterSize(25);
    newhighscore.setPosition({190, 180});
    newhighscore.setString("NEW   HIGH   SCORE !");
    newhighscore.setFillColor(sf::Color::Cyan);

    highscore.setFont(Font);
    highscore.setCharacterSize(25);
    highscore.setPosition({230,180});
    highscore.setString("HIGH    SCORE");

    yourscore.setFont(Font);
    yourscore.setCharacterSize(25);
    yourscore.setPosition({230,280});
    yourscore.setString("YOUR   SCORE");

    menu.setFont(Font);
    menu.setCharacterSize(20);
    menu.setPosition(170,440);
    menu.setFillColor(sf::Color::Green);
    menu.setString("PRESS   ESC   TO   RETURN   TO   MENU");


}


int GameOver::run(sf::RenderWindow &m_window, int &score, int &hscore) {


    if (score > hscore){
        hscore = score;
        newhs = true;
    }
    else {
        newhs = false;
    }


    yourscore.setString("YOUR   SCORE      " + std::to_string(score));
    highscore.setString("HIGH   SCORE       " + std::to_string(hscore));
    newhighscore.setString("NEW   HIGH   SCORE !      " + std::to_string(hscore));

    sf::Clock clock;
    while(m_window.isOpen()) {

        sf::Time deltaT = clock.getElapsedTime();




        processEvents(m_window);
        update(deltaT, score);
        render(m_window);

        if (deltaT.asSeconds() > .9f){
            clock.restart();
        }
        if (m_enter){
            m_enter = false;
            return 2;
        }
        if (m_esc){
            m_esc = false;
            return 0;
        }
    }
    return (-1);
}


void GameOver::processEvents(sf::RenderWindow &m_window) {
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

void GameOver::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if(key == sf::Keyboard::Return)
        m_enter = isDown;
    if(key == sf::Keyboard::Escape)
        m_esc = isDown;
}

int GameOver::update(sf::Time deltaT, int &score){
    if (deltaT.asSeconds() > .9f){
        if (blink) {
            cont.setFillColor(sf::Color::Red);
            blink = false;
        }
        else {
            cont.setFillColor(sf::Color::Yellow);
            blink = true;
        }

    }
    return 0;

}

void GameOver::render(sf::RenderWindow &m_window) {
    m_window.clear();

    m_window.draw(dead);
    m_window.draw(cont);
    if (newhs){
        m_window.draw(newhighscore);
    }
    else {
        m_window.draw(highscore);
    }
    m_window.draw(yourscore);
    m_window.draw(menu);

    m_window.display();
}
