g++ -c src/main.cpp src/game.cpp src/entity.cpp src/player.cpp src/states/states.cpp src/states/gameState.cpp
g++ main.o game.o entity.o player.o states.o gameState.o -o bin/game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
./bin/game
