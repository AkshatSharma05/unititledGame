#pragma once
#include "entity.hpp"

class Player
: public Entity
{
public:
    Player();
    void update(const float& dt);
    void render(RenderTarget* target);
};