#ifndef GAME_H
#define GAME_H

#include<string>
#include<vector>

#include "character.h"
#include "room.h"
#include "enemy.h"
#include "crawler.h"
#include "slime.h"
#include "venom.h"
#include "statueman.h"
#include "supervenoncrawler.h"
using namespace std;

/****************** 1.Destructors */
/****************** 3.Templates */

class Game
{
public:
    Game();
    ~Game();/****************** 1.Destructors */
    void reset(bool show_update = true);
    void map();
    void info();
    void go(string direction);
    void teleport();
    void take(string take);
    void update_screen();
    int roomContains(string item);
    Character &getPlayer();
    void setOver(bool over);
    bool is_over();
    void setCurrentRoom(Room *next);
    string take(Item *item);
    bool doorLocker(bool smith);
    void moveEnemy(enemy *a);
    void encounterEnemy();
    void attack();
    string randomDirection();
    char roomToChar(string s);
    void Hurt();
    void superEnemy();

    template< typename T > /****************** 3.Templates */
    void displayStats(T stat)
    {
        if(std::is_same<T, int>::value){
      cout<<stat<<"HB" <<endl;
        }
        if(std::is_same<T, string>::value){
      cout<<stat<<"ST" <<endl;
        }

    }


private:
    Character      player;
    enemy            ven;
    enemy           ven2;
    enemy           venomSuper;
    crawler            c;
    slime              s;
    venom              v;
    statueman         st;
    superVenonCrawler vs;
    Character      *pointer;
    vector<Room *> rooms;
    vector<Item *> items;
    bool           gameOver;   
    bool pickerP = true;
    bool pickerC = true;
    bool pickerK = true;
    bool pickerG = true;
};
#endif // GAME_H
