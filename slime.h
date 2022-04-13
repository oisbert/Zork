#ifndef SLIME_H
#define SLIME_H
#include "enemy.h"

/****************** 2. Inheritance (including virtual methods) and cascading constructors */

class slime : public enemy
{
public:
    slime();
    slime(string name,int health,int stamina);
    void stats();
    void encouterEnemy(Character &test); //.7 polymorphism overidded from enemy

private:
    int health;
    int stamina;
};

#endif // SLIME_H
