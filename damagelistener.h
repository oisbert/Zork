#ifndef DAMAGELISTENER_H
#define DAMAGELISTENER_H

//This is a damage listener for week 4 labs
#include "eventlistener.h"


class Game;

class damagelistener : public EventListener
{
public:
    damagelistener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // DAMAGELISTENER_H
