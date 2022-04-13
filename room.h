#ifndef ROOM_H
#define ROOM_H

#include<map>
#include<string>
#include "item.h"
#include <vector>
#include "enemy.h"

using namespace std;
using std::vector;

class Room
{
public:
    Room(string name);
    string getName();
    void setExits(Room *north, Room *east, Room *south, Room *west);
    Room *getExit(string direction);
    void addItem(Item *inItem);
    string displayItem();
    string displayEnemy();
    string longDescription();
    int roomContains(string item);
    int roomContainsItem(string item);
    int isItemInRoom(string inString);
    string tempRoomDescription();
    void addAlien(enemy *inenemy);
    int roomContainsEnemy(string enemy);
    string displayEnemyLeaderBoard();
    void removeItem(Item inItem);
private:
    string name;
    map<string, Room *> exits;
    vector <Item> itemsInRoom;
    vector <enemy> enemyInRoom;
};

#endif // ROOM_H
