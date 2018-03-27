#include "Game.h"

Gardener *gardener = new Gardener();
Bug *bug1 = new Bug();
Bug *bug2 = new Bug();
Bug *bug3 = new Bug();
Tomato *tomato1 = new Tomato();
Tomato *tomato2 = new Tomato();
Tomato *tomato3 = new Tomato();
Tomato *tomato4 = new Tomato();
Tomato *tomato5 = new Tomato();

Game::Game()
{



//initialize everything (start with one gardener, 3 bugs, 5 tomatoes)


    gardener->load("farmer sprite.png");
    gardener->setScale(.6f);
    gardener->setWidth(100);
    gardener->setHeight(100);

    m_player = gardener;

    bug1->load("bug sprite.png");
    bug1->setWidth(63);
    bug1->setHeight(64);
    bug1->setScale(1.5f);


    bug2->load("bug sprite.png");
    bug2->setWidth(63);
    bug2->setHeight(64);
    bug2->setScale(1.5f);

    bug3->load("bug sprite.png");
    bug3->setWidth(63);
    bug3->setHeight(64);
    bug3->setScale(1.5f);


    tomato1->load("newtomato.png");
    tomato1->setScale(.4);
    tomato1->move(sf::Vector2f(150,80));


    tomato2->load("newtomato.png");
    tomato2->move(sf::Vector2f(200,300));
    tomato2->setScale(.4);

    tomato3->load("newtomato.png");
    tomato3->move(sf::Vector2f(40,400));
    tomato3->setScale(.4);

    tomato4->load("newtomato.png");
    tomato4->move(sf::Vector2f(500, 250));
    tomato4->setScale(.4);

    tomato5->load("newtomato.png");
    tomato5->move(sf::Vector2f(360,360));
    tomato5->setScale(.4);


    objVec.push_back(gardener);
    objVec.push_back(bug1);
    objVec.push_back(bug2);
    objVec.push_back(bug3);
    objVec.push_back(tomato1);
    objVec.push_back(tomato2);
    objVec.push_back(tomato3);
    objVec.push_back(tomato4);
    objVec.push_back(tomato5);

    tomatoes.push_back(tomato1);
    tomatoes.push_back(tomato2);
    tomatoes.push_back(tomato3);
    tomatoes.push_back(tomato4);
    tomatoes.push_back(tomato5);

    bugs.push_back(bug1);
    bugs.push_back(bug2);
    bugs.push_back(bug3);



}

int Game::run(sf::RenderWindow &m_window, int &score, int &hscore) {
    score = 0;
    gardener->setDirection(2);
    gardener->setStartCol(200);
    gardener->setPosition(0,0);
    bug1->setPosition(550, 400);
    bug1->setJ(0);
    bug2->setPosition(0, 260);
    bug2->setJ(551);
    bug3->setPosition(550, 15);
    bug3->setJ(1201);
    tomato1->setPosition(150,80);
    tomato2->setPosition(200,300);
    tomato3->setPosition(40,400);
    tomato4->setPosition(500, 250);
    tomato5->setPosition(360,360);



    sf::Clock clock;
    score = 0;
    while(m_window.isOpen()) {
        sf::Time deltaT = clock.restart();
        processEvents(m_window);
        int upOut = update(deltaT, score);
        if (upOut > 0) {
            return upOut;
        }
        render(m_window);
    }
    return (-1);
}

void Game::processEvents(sf::RenderWindow &m_window) {
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

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if (key == sf::Keyboard::Left) {
        m_left = isDown;
        gardener->setDirection(1);
        gardener->setStartCol(100);
    }
    if (key == sf::Keyboard::Right) {
        m_right = isDown;
        gardener->setDirection(2);
        gardener->setStartCol(200);
    }
    if (key == sf::Keyboard::Up) {
        m_up = isDown;
        gardener->setDirection(3);
        gardener->setStartCol(300);
    }
    if (key == sf::Keyboard::Down) {
        m_down = isDown;
        gardener->setDirection(0);
        gardener->setStartCol(0);
    }
}

//use time since last update to get smooth movement
int Game::update(sf::Time deltaT, int &score) {
    //Look a vector class!
    sf::Vector2f movement(0.0f, 0.0f);
    int currentDirection = gardener->getDirection();
    sf::Vector2f gpos = gardener->getPosition();
    gpos.x += 5;
    gpos.y += 5;
    sf::Vector2f gsize(50, 50);
    sf::FloatRect gardRect(gpos,gsize);

    int u = 0;
    while (u < bugs.size()) {
        sf::Vector2f bpos = bugs[u]->getPosition();
        bpos.x += 35;
        bpos.y += 35;
        sf::Vector2f bsize(26,26);
        sf::FloatRect bugRect(bpos,bsize);
        if (gardRect.intersects(bugRect)){
            return 3;
        }
        u++;
    }
    int v = 0;
    while (v <tomatoes.size()){
        sf::Vector2f tpos = tomatoes[v]->getPosition();
        tpos.x += 10;
        tpos.y += 10;
        sf::Vector2f tsize(12,12);
        sf::FloatRect tomRect(tpos,tsize);
        if (gardRect.intersects(tomRect)){
            if(v == 0) {
                    tomato1->move(sf::Vector2f(800, 800));
                    int randx1 = rand() % 400 + 1;
                    int randy1 = rand() % 400 + 1;
                    tomato1->setPosition(randx1, randy1);
                score += 1;
            }

            if (v == 1) {
                    tomato2->move(sf::Vector2f(800, 800));
                    int randx2 = rand() % 200 + 50;
                    int randy2 = rand() % 200 + 50;
                    tomato2->setPosition(randx2, randy2);
                score += 1;
            }

            if (v == 2){
                    tomato3->move(sf::Vector2f(800, 800));
                    int randx3 = rand() % 300 + 1;
                    int randy3 = rand() % 300 + 1;
                    tomato3->setPosition(randx3, randy3);
                score  += 1;
            }

            if (v == 3){
                    tomato4->move(sf::Vector2f(800, 800));
                    int randx4 = rand() % 300 + 200;
                    int randy4 = rand() % 100 + 1;
                    tomato4->setPosition(randx4, randy4);
                score += 1;
            }

            if (v == 4){
                    tomato5->move(sf::Vector2f(800, 800));
                    int randx5 = rand() % 400 + 200;
                    int randy5 = rand() % 300 + 100;
                    tomato5->setPosition(randx5, randy5);
                score += 1;
            }

        }
        v++;

    }
    if(gpos.x < -30 || gpos.x > 640 || gpos.y < -30 || gpos.y > 480 ){
        return 3;
    }



    if (currentDirection == 0) {
        movement.y += m_speed;
    }
    if (currentDirection == 1) {
        movement.x -= m_speed;
    }
    if (currentDirection == 2) {
        movement.x += m_speed;
    }
    if (currentDirection == 3) {
        movement.y -= m_speed;
    }
    //loop through vector & update
    int i = 0;
    while (i < objVec.size()) {
        objVec[i]->update(deltaT.asSeconds());
        i++;
    }

    m_player->move(movement * deltaT.asSeconds());

    return 0;

}

void Game::render(sf::RenderWindow &m_window){
    m_window.clear();
    m_window.clear(sf::Color(0, 166, 17));

    m_player->draw(m_window);
    //loop through vector and call draw on each
    int i = 0;
    while (i < objVec.size()) {
        objVec[i]->draw(m_window);
        i++;
    }
    m_window.display();
}

