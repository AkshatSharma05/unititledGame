#include "states.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys){
    window = window;
    this->supportedKeys = supportedKeys;
    quit = false;
}

State::~State(){
    
}

void State::checkForQuit(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        quit = true;
    }
}

const bool& State::getQuit() const{
    return quit;
}