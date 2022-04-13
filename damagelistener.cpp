#include "damagelistener.h"

#include<iostream>

#include "game.h"

damagelistener::damagelistener(Game *game)
{
    this->game = game;
}

void damagelistener::run(void *)
{

    cout << endl;

    game->Hurt();

}
