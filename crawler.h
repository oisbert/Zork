#ifndef CRAWLER_H
#define CRAWLER_H
#include "enemy.h"

/****************** 2. Inheritance (including virtual methods) and cascading constructors */

class crawler : public enemy
{
public:
    crawler();
    crawler(string name,int health,int stamina);
    void stats();
    void encouterEnemy(Character &test);//.7 polymorphism overidded from enemy


};

#endif // CRAWLER_H
