#include "headers/player.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Player::Player(){
    velocity = 25;
}

void Player::update(const float& dt){
    if(Keyboard::isKeyPressed(Keyboard::A)){
        moveEntity(dt, Vector2f(-1.f, 0.f));
    }
    if(Keyboard::isKeyPressed(Keyboard::S)){
        moveEntity(dt, Vector2f(0.f, 1.f));
    }
    if(Keyboard::isKeyPressed(Keyboard::W)){
        moveEntity(dt, Vector2f(0.f, -1.f));
    }
    if(Keyboard::isKeyPressed(Keyboard::D)){
        moveEntity(dt, Vector2f(1.f, 0.f));
    }

    position = entitySprite.getPosition();
    std::cout << position.x << ", " << position.y << std::endl;
}

void Player::render(RenderTarget* target){
    target->draw(entitySprite);
}