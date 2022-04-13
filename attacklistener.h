#ifndef ATTACKLISTENER_H
#define ATTACKLISTENER_H

//This is an attack listener fo week 5 assignment
#include "eventlistener.h"

class Game;

// A listener for the exit command
class attackListener : public EventListener
{
public:
    attackListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // ATTACKLISTENER_H
