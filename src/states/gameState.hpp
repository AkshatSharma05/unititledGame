#pragma once

#include "states.hpp"

class gameState : public State{
public:
    //const dest    
    gameState(sf::RenderWindow* window);
    virtual ~gameState();

    //funcs
    void endState();

    void updateInput(const float dt);
    void update(const float dt);
    void render(sf::RenderTarget* target = nullptr);

private:
    Player player;
};