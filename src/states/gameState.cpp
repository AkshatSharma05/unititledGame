#include "gameState.hpp"

gameState::gameState(sf::RenderWindow* window) : State(window)
{
    player.setSprite("data/_sprites/tree.png");
}

gameState::~gameState(){

}

void gameState::endState(){
    std::cout << "Ending game state" << std::endl;
}

void gameState::updateInput(const float dt){
    checkForQuit();
}

void gameState::update(const float dt){
    updateInput(dt);
    player.update(dt);
}

void gameState::render(sf::RenderTarget* target){
    if(!target){
        target = window;
    }
    player.render(target);
}

