#include "venom.h"

venom::venom(){}

venom::venom(string name,int health, int stamina):enemy(name,health,stamina){};

void venom::encouterEnemy(Character &test) //friend
{
    if(test.currentRoom == getCurrentRoom())
    {
        int venomStick = (rand() % 10)+1;
        test.Setter(test.health - venomStick, "health");
        stats();
        cout << endl;
    }
}


void venom::stats()
{
  cout << "you have encountered a "<< getName()<< "it is trying to combine with you kill it before it takes over "<< endl;
  cout << getName() <<" " << "Stats" <<" : " <<"HP: " << getHealth() << " ST: " << getStamina() << endl;
}
