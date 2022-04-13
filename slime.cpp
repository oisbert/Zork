#include "slime.h"


slime::slime(){}

slime::slime(string name,int health, int stamina):enemy(name,health,stamina){this->health = health; this->stamina = stamina;}

void slime::encouterEnemy(Character &test) //friend
{
    if(test.currentRoom == getCurrentRoom())
    {
        int slimespit = (rand() % 5)+1;
        test.Setter(test.health - slimespit, "health");
        stats();
        cout << "you have encountered a slime he it shooting toxic slime at you "<< endl;
        cout << endl;
    }
}

void slime::stats()
{
  cout << getName() <<" " << "Stats" <<" : " <<"HP: " << getHealth() << " ST: " << getStamina() << endl;
}
