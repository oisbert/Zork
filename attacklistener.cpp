#include "attacklistener.h"

#include "game.h"

attackListener::attackListener(Game *game)
{
    this->game = game;
}

void attackListener::run(void *)
{
    game->attack();
}
