#ifndef ENEMY_H
#define ENEMY_H
#include "enemyAbstract.h"
#include "character.h"

class Room;

/****************** 2. Inheritance (including virtual methods) and cascading constructors
                    4. Unary operator overloading
                    5. Binary operator overloading
                    6. Friends
                    7. Virtual functions and polymorphism */

class enemy : public enemyAbstract
{
private:
    string name;
    int health = 0;
    int stamina = 0;
    string description;
    Room *currentRoom;
public:
    enemy();
    enemy(string name,int health,int stamina);
    Room  *getCurrentRoom();
    void setCurrentRoom(Room *next);
    int Armour(int power);
    string getShortDescription();
    void Enemies();
    string getName(){ return name;   }
    int getHealth() { return health; }
    int getStamina(){ return stamina;}

    string setName(string name){this->name = name; return name;}
    int setHealth(int health)  {this->health = health;     return health;}
    int setStamina(int stamina){this->stamina = stamina; return stamina;}

    virtual void encouterEnemy(Character &test); //7. Virtual functions, polymorphism and also utilizes friend class
    virtual void stats();                        //7. Virtual functions

    enemy  operator+(enemy b);  // 5. Binary operator overloading
    enemy operator -();        //4. Unary operator overloading
};

#endif // ENEMY_H
