#include "headers/entity.hpp"
#include "headers/game.hpp"

Entity::Entity(){
    position.x = 0;
    position.y = 0;
    velocity = 0;
    acceleration = 0;
}

Entity::~Entity(){
    
}

void Entity::setSprite(const char* path){
    entityTexture.loadFromFile(path);
    entitySprite.setTexture(entityTexture);
}

void Entity::moveEntity(const float dt, Vector2f dir){
    entitySprite.move(dir.x * velocity * dt, dir.y * velocity * dt);
}

