#ifndef SUPERVENONCRAWLER_H
#define SUPERVENONCRAWLER_H
#include "enemy.h"

/****************** 2. Inheritance (including virtual methods) and cascading constructors */

class superVenonCrawler: public enemy
{
public:
    superVenonCrawler();
    superVenonCrawler(string name,int health,int stamina);
    void encouterEnemy(Character &test);//.7 polymorphism overidded from enemy
    void stats();
    void setName(string name);
    string getName();
    void setHealth(int health);
    int getHealth();
private:
    string name;
    int health = 200;
    int stamina;
  };

#endif // SUPERVENONCRAWLER_H
