#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "RegularGameObject.h"
#include "AnimatedGameObject.h"
#include "Gardener.h"
#include "Bug.h"
#include "Tomato.h"
#include "Screen.h"

class Game : public Screen{
public:
    //use default screen size
    Game();
    //run the game
    int run(sf::RenderWindow &m_window, int &score, int &hscore);

private:
    std::vector<GameObject*> objVec;//*********
    std::vector<GameObject*> tomatoes;
    std::vector<GameObject*> bugs;
    void processEvents(sf::RenderWindow &m_window);
    //update the game objects
    int update(sf::Time deltaT, int &score);
    //draw the scene
    void render(sf::RenderWindow &m_window);
    //handle input from the user
    void handlePlayerInput(sf::Keyboard::Key key, bool isDown);

    sf::RenderWindow m_window;

    GameObject* m_player = new AnimatedGameObject();

    //TODO::these should be moved to game object
    float m_speed = 120.0f;
    bool m_left = false;
    bool m_right = false;
    bool m_up = false;
    bool m_down = false;
};



