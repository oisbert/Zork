#include "keylistener.h"
#include "game.h"

keyListener::keyListener(Game *game)
{
    this->game = game;
}

void keyListener::run(void *)
{
    cout << endl;
    cout << "Victory!" << endl;
    game->setOver(true);
}
