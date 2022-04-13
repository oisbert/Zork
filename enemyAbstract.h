
#ifndef ENEMYABSTRACT_H
#define ENEMYABSTRACT_H

#include <iostream>

using namespace std;

/****************** 2. Inheritance (including virtual methods) and cascading constructors */

class Room;

class enemyAbstract
{

public:

    virtual void stats() = 0;

};


#endif // ENEMYABSTRACT_H
