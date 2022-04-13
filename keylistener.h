#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include "eventlistener.h"

// VictoryListener.h
class Game;

// A listener for the good ending
class keyListener : public EventListener
{
public:
    keyListener(Game *game);
    void run(void *args) override;
private:
   Game *game;
};

#endif // KEYLISTENER_H
