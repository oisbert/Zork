#include "room.h"
#include <algorithm>

Room::Room(string name) :
    name(name)
{
    exits["north"] = nullptr;
    exits["east"]  = nullptr;
    exits["south"] = nullptr;
    exits["west"]  = nullptr;

}

string Room::getName()
{
    return name;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west)
{
    exits["north"] = north;
    exits["east"]  = east;
    exits["south"] = south;
    exits["west"]  = west;
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(*inItem);
}

void Room::addAlien(enemy *inenemy)
{
    enemyInRoom.push_back(*inenemy);
}

Room *Room::getExit(string direction)
{
    return exits[direction];
}

string Room::longDescription() {
    return "room = " + getName() + ".\n" + displayItem() +"\n"+ displayEnemy();
}

string Room::tempRoomDescription(){ //tempory room
    return "You need a key to enter the next room go back and find it";
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

string Room::displayEnemy() {
    string tempString = "Enemies in room = ";
    int sizeItems = (enemyInRoom.size());
    if (enemyInRoom.size() < 1) {
        tempString = "no Enemies in room";
        }
    else if (enemyInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + enemyInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

string Room::displayEnemyLeaderBoard() {
    string tempString = "Enemies defeated = ";
    int sizeItems = (enemyInRoom.size());
    if (enemyInRoom.size() < 1) {
        tempString = "You defeated no Enemies :(";
        }
    else if (enemyInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + enemyInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::roomContains(string item)
{
    string str = longDescription();
    size_t found = str.find(item);
      if (found != string::npos)
      {
          return 1;
      }
        return 0;
}

int Room::roomContainsEnemy(string enemy)
{
    string str = displayEnemy();
    size_t found = str.find(enemy);
      if (found != string::npos)
      {
          return 1;
      }
        return 0;
}

int Room::roomContainsItem(string item)
{
    string str = displayItem();
    size_t found = str.find(item);
      if (found != string::npos)
      {
          return 1;
      }
        return 0;
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
               // cout << "test" << endl;
                return x;
            }
            x++;
            }
        }
    return -1;
}
