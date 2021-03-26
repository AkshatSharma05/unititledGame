#include "gameState.hpp"

gameState::gameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) 
    : State(window, supportedKeys)
{
    player.setSprite("data/_sprites/tree.png");
    this->initKeybinds();
}

gameState::~gameState(){

}

void gameState::initKeybinds(){
    this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
    this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
    this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
    this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

void gameState::endState(){
    std::cout << "Ending game state" << std::endl;
}

void gameState::updateInput(const float dt){
    this->checkForQuit();
}

void gameState::update(const float dt){
    this->updateInput(dt);
    this->player.update(dt);
}

void gameState::render(sf::RenderTarget* target){
    if(!target){
        target = this->window;
    }
    this->player.render(target);
}

