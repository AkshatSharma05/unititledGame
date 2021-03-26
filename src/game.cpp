#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/game.hpp"
#include "headers/DEFINITIONS.h"
#include <iostream>

using namespace sf;

Game::Game(){
    windowInit();
    initKeys();
    statesInit();
}

Game::~Game(){
    window.~RenderWindow();

    while(!states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

void Game::windowInit(){
    window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game");
    window.setFramerateLimit(FRAMERATE_LIMIT);
}

void Game::statesInit(){
    states.push(new gameState(&window, &supportedKeys));
}

void Game::initKeys(){
    this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
}

void Game::updateDt(){
    dt = dtClock.restart().asSeconds(); //returns time between each frame
}

void Game::render(){
    window.clear();

    if(!states.empty()){
        states.top()->render(&window);
    }

    window.display();
}

void Game::handleEvents(){
    while(window.pollEvent(event)){
        if(event.type == Event::Closed){
            window.close();
        }
    }
}

void Game::update(){
    handleEvents();

    if(!states.empty()){
        states.top()->update(dt);

        if(states.top()->getQuit()){
            states.top()->endState();
            delete states.top();
            states.pop();
        }
    }
    //end game
    else{
        endGame();
        window.close();
    }
}

void Game::endGame(){
    cout << "ending app\n" << endl;
}

void Game::run(){
    while(window.isOpen()){
        updateDt();
        update();
        render();
    }
}