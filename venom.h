#ifndef VENOM_H
#define VENOM_H
#include "enemy.h"

/****************** 2. Inheritance (including virtual methods) and cascading constructors */

class venom : public enemy
{
public:
    venom();
    venom(string name,int health,int stamina);
    void encouterEnemy(Character &test); //.7 polymorphism overidded from enemy
    void stats();

};

#endif // VENOM_H
