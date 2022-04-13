#include "supervenoncrawler.h"



superVenonCrawler::superVenonCrawler(string name,int health, int stamina):name(name),health(health),stamina(stamina){};

void superVenonCrawler::encouterEnemy(Character &test) //friend
{
    if(test.currentRoom == getCurrentRoom())
    {
        int venomStick = (rand() % 10)+1;
        test.Setter(test.health - venomStick, "health");
        stats();
        cout << endl;
    }
}

void superVenonCrawler::setName(string name)
{
   this->name = name;
}

string superVenonCrawler::getName()
{
    return name;
}

void superVenonCrawler::setHealth(int health)
{
    this->health = health;
}

int superVenonCrawler::getHealth()
{
    return health;
}

void superVenonCrawler::stats()
{
  cout << "you have encountered a superVenomCrawler goodluck :( "<< endl;
  cout << getName() <<" " << "Stats" <<" : " <<"HP: " << getHealth() << " ST: " << getStamina() << endl;
}
