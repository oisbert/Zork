#include "crawler.h"

crawler::crawler(){}

crawler::crawler(string name,int health, int stamina):enemy(name,health,stamina){} //cascading constructors


void crawler::encouterEnemy(Character &test) //friend
{
    if(test.currentRoom == getCurrentRoom())
    {
        int crawlerbite = (rand() % 40)+1;
        test.Setter(test.health - crawlerbite, "health");
        cout << "you have encountered a crawler is biting you "<< endl;
        cout << endl;
    }
}

void crawler::stats()
{
  cout << getName() <<" " << "Stats" <<" : " <<"HP: " << getHealth() << " ST: " << getStamina() << endl;
}



