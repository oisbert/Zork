#include "enemy.h"
#include "item.h"
enemy::enemy(string name,int health, int stamina):health(health),stamina(stamina) //initializerlist
{
    this->name = name;
    currentRoom = nullptr;
}

enemy::enemy(){};

int enemy::Armour(int power)
{
    return power;
}

string enemy::getShortDescription() //overriding get shortdescription
{
    return description;
}

void enemy::encouterEnemy(Character &test) //friend
{
    if(test.currentRoom == getCurrentRoom())
    {
        int venomspit = (rand() % 50)+1;
        test.Setter(test.health - venomspit, "health");
        stats();
        cout << endl;
    }

}

Room *enemy::getCurrentRoom()
{
    return currentRoom;
}


void enemy::setCurrentRoom(Room *next)
{
    currentRoom = next;
}

void enemy::stats()
{
    cout << "you have encountered " << getName() <<" "<<"it is attacking you "<< endl;
    cout << getName() <<" " << "Stats" <<" : " <<"HP: " << getHealth() << " ST: " << getStamina() << endl;
}

enemy enemy::operator+(enemy b){
    string name = "superVenomCrawler";
    int health = this->health + b.health;
    int stamina = this->stamina + b.stamina;
    enemy temp = * new enemy(name,health,stamina);
    return temp;
}

enemy enemy::operator-()
{
    string name = this->name;
    int health = this->health--;
    int stamina = this->stamina--;
    enemy temp = *new enemy(name,health,stamina);
    return temp;
}









