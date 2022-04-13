#ifndef TAKELISTENER_H
#define TAKELISTENER_H

#include "eventlistener.h"

class Game;

class takelistener : public EventListener
{
public:
    takelistener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // TAKELISTENER_H
