#include "character.h"
#include "eventmanager.h"

Character::Character(string name) : health(100),stamina(100)
{
    this->name = name;// We need to use "this->" to differentiate between the "name" argument and the "name" from the class.
    currentRoom = nullptr;
}

Character::Character() : health(100),stamina(100)
{

}

string Character::getName()
{
    return name;
}

int Character::getHealth()
{
    return health;
}

double Character::getStamina()
{
    return stamina;
}

Room *Character::getCurrentRoom()
{
    return currentRoom;
}


void Character::setCurrentRoom(Room *next)
{
    currentRoom = next;
}

void Character::addCItem(Item *Item)  //declares a point to item
    {
        itemsInCharacter.push_back(*Item);
    }

bool Character::boolBagContains(string item)
{
    string str = longDescription();
    size_t found = str.find(item);
      if (found != string::npos)
      {
       return true;
      }
       return false;
}


string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}

void Character::removeAllItems()
{
    itemsInCharacter.clear();
}
