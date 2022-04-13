#ifndef STATUEMAN_H
#define STATUEMAN_H
#include "enemy.h"

/****************** 2. Inheritance (including virtual methods) and cascading constructors */

class statueman : public enemy
{
public:
    statueman();
    statueman(string name,int health, int stamina);
    void encouterEnemy(Character &test);//.7 polymorphism overidded from enemy
    void stats();
    //int getHealth();
private:
    int health;
    int stamina;
};

#endif // STATUEMAN_H
