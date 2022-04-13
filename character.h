#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>

using namespace std;

#include "item.h"
#include <string>
#include "characterdeathlistener.h"
#include "eventmanager.h"

// No need to include room since we're only working with pointers.
// This is how we tell the compiler "there will be a room eventually".
// This is called a "forward declaration".

class Room;

#include <vector>
using std::vector;
using namespace std;

/****************** 3. Templates */
/****************** 6. Friends */

class Character
{
  friend class enemy;
  friend class slime;
  friend class venom;
  friend class statueman;
  friend class crawler;
  friend class superVenonCrawler;
public:
    Character(string name);
    Character();
    string getName();
    int    getHealth();
    double    getStamina();
    Room  *getCurrentRoom();
    string description;
    string longDescription();
    bool boolBagContains(string item);
    void setName(string name);
    void setCurrentRoom(Room *next);
    void addCItem(Item *Item);
    vector <Item> itemsInCharacter;
    void removeAllItems();

    template< typename T >  /****************** 3. Templates */
    void Setter(T set ,string varName )
    {
       if(varName == "health" )
       {
          this->health = set;
           if(health <= 0)
           {
               EventManager::getInstance().trigger("characterdeath",this);
           }
       }
       else if(varName == "stamina")
       {
          this->stamina = set;
           if(stamina <= 0){
               EventManager::getInstance().trigger("characterdeath",this);
           }
       }
       else
       {
           EventManager::getInstance().trigger("characterdeath",this);
       }
    }



private:
    string name;
    int health;
    double stamina;
    Room *currentRoom;
    void encouterEnemy(Character &test); /****************** 6. Friends */
};

#endif // CHARACTER_H
