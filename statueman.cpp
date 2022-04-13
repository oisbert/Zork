#include "statueman.h"

statueman::statueman()
{

}

statueman::statueman(string name,int health, int stamina):enemy(name,health,stamina)
{
    this->health = health;
    this->stamina = stamina;
}


void statueman::encouterEnemy(Character &test) //friend
{
    if(test.currentRoom == getCurrentRoom())
    {
        int rocks = (rand() % 60)+1;
        test.Setter(test.health - rocks, "health");
        stats();
        cout << endl;
    }
}

void statueman::stats()
{
    cout << "you have encountered a statueman he is throwing rocks at you "<< endl;
    cout << "**warning rocks do alot of damage**"<<endl;
    cout << getName() <<" " << "Stats" <<" : " <<"HP: " << getHealth() << " ST: " << getStamina() << endl;
}
