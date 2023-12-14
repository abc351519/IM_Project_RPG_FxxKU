#ifndef GAME_H
#define GAME_H

#include "event.h"

class Game
{
private:
    Event** currentEvent;
public:
    Game();
    ~Game();
};

Game::Game(/* args */)
{
}

Game::~Game()
{
}


#endif