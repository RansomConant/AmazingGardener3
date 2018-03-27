#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "Game.h"
#include "Menu.h"
#include "GameOver.h"
#include "Story.h"
#include <iostream>

int main() {

    std::vector<Screen *> Screens;
    int screen = 0;

    //Window creation

    sf::RenderWindow m_window(sf::VideoMode(640, 480), "Amazing Gardener 3");
    int score = 0;
    int hscore = 0;

    //Screens preparations
    Menu menu;
    Screens.push_back(&menu);
    Story story;
    Screens.push_back(&story);
    Game game;
    Screens.push_back(&game);
    GameOver gameover;
    Screens.push_back(&gameover);
//    //Main loop
    while (screen >= 0) {


        screen = Screens[screen]->run(m_window, score, hscore);

    }
}
