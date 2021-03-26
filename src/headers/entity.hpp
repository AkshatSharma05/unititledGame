#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace sf;
using namespace std;

class Entity
{
public:
    //vars
    Vector2f position;
    float velocity;
    float acceleration;
    Sprite entitySprite;
    
    //funcs
    Entity();
    ~Entity();
    void setSprite(const char* p_path);
    void moveEntity(const float p_dt, Vector2f p_dir);
    virtual void update(const float& dt) = 0;
    virtual void render(RenderTarget* target) = 0;

private:
    Texture entityTexture;
};