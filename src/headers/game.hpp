#pragma once
#include "../states/gameState.hpp"
#include <stack>
#include <map>

using namespace sf;

class Game{
public:
    //const dest
    Game();
    ~Game();

    void endGame();

    //update
    void handleEvents();
    void update();
    void updateDt();
    
    //rendering 
    void render();

    //mains
    void run();
    
private:
    RenderWindow window;
    Event event;
    
    Clock dtClock;
    float dt;

    std::stack<State*> states;
    std::map<std::string, int>supportedKeys;
    
    //funcs
    void windowInit();
    void statesInit();
    void initKeys();
};