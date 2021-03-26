#pragma once
#include "../headers/entity.hpp"
#include "../headers/player.hpp"

class State{
private:
    std::vector<sf::Texture> textures;
    bool quit;

public:
    sf::RenderWindow* window;
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void updateInput(const float dt) = 0;
    const bool& getQuit() const;
    virtual void checkForQuit();
    virtual void endState() = 0;

    virtual void update(const float dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};