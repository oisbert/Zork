#include "game.h"

#include<ctime>
#include<iostream>
#include <bits/stdc++.h>
#include "eventmanager.h"
#include "room.h"

#include "golistener.h"
#include "maplistener.h"
#include "infolistener.h"
#include "restartlistener.h"
#include "teleportlistener.h"
#include "takelistener.h"
#include "exitlistener.h"
#include "characterdeathlistener.h"
#include "enterroomlistener.h"
#include "victorylistener.h"
#include "defeatlistener.h"
#include "attacklistener.h"
#include "damagelistener.h"

/*lab 4 assignment
 *"Adding items" to room.. I have added items to the room in the "update_screen()" method
 *Items add to room if the conditions in the if statment are met
 *"take" I have built a take listener similar to the map listener
 * Along with the I have built a method which carries out the take option
 * take(string item) takes in the name of the item you have picked up and carries out different operations according to the item
 * "Added damageListener" the damage listener will trigger when the player picks up the "curse" object this is also found in the take method
 * "The key item" is located in room D you will need this key to complete the game and get into J
 * I edited the code inside the method "go" to lock the door
*/

/*lab 5 assignment
 * I have made some changes since the previose change log
 * Edited the map method to display the current room the player is in, the enemy and a new obstacle the player must face called a super enemy
 * I also created a roomToChar method which basically just changes the string name in room to a character this is for the map method
 * For the enemy movement statueMan is a stationary enemy located in D guarding the key.
 * The venom,crawler and slime can all navigate the map moving to adjacent rooms everytime the player moves
 * I created a method called moveEnemy which is recursively called until the direction is found and the enemy can move out of the room
 * I also created a randomDirection generator which simply generates the direction in which the enemy will go in randomly
 * The moveEnemy() method is called in the go() method as I wanted them to move everytime the player moves
 * I have also made an encounterEnemy method in the class "enemy" which allows the enemy to attack on initial encounter and print out the enemy stats
 * The encounterEnemy method utilizes the "friends functionality in c++"
 * Attack() method and listener
 * The Attack method is called when the attack command is entered in the cmd...the listener works similar to the map function
 * At the moment I have made all the enemies easy to defeat for testing purposes additional changes will be made to balance the game
 * You can change the enemy damage in the Setters of the attack() method if you like
 * Currently enemies stamima does not do anything will make changes for the final release plan is to show the power of attack;
 *
 * Additional changes
 * Updated the info screen to contain a map and a warning message if a superEnemy is created
 * Added superEnemys...A super enemy occurs if a venom and crawler bump into each other on the map
 * They combine stats using binary operator overloading
 * once the enemy is created the two combined enemys are dumped and the Super enemy is spawned
 */

/* ASSIGNMENT PARTS LOCATIONS CS4076
   1.Destructors - Located in game class

   2.Inheritance (including virtual methods) and cascading constructors - Inherites classes:            ,cascading contructors enemy cascades to crawler venom slime stutueman;
                                                                           enemyAbstract.h
                                                                                 |
                                                                               enemy
                                                                   |     |       |      |         |
                                                                slime crawler venom  statueman supervenomcrawler

   3.Templates - template is located in the "character" class it is a different way of writing a setter method the template allows you to type in a double or an int

   4.Unary operator overloading - this overloads a "-" symbol inside the "enemy" class..implememented in the "take" method inside "game" class...decreases enemys health when a potion is picked up

   5.Binary operator overloading - this overloads the "+" symbol on an enemy object it is located inside the "enemy" class...This is used for creating the supervenomcrawler it combines the stats of enemys located in the same room

   6.Friends -  all "enemy" classes are friends with the "character" class this gave me access to the characters health so I could create an encounterenemy method inside each character class Example found in character...and all enemy classes

   7.Virtual functions and polymorphism - example of virtual functions can be found in "enemy" class which includes the virtual function encounterEnemy()
                                        - I have also overidded the encounter enemy class in each class as an example of polymorphism
                                        - encounter enemy has the same parameter types and return types in each class but is implemented diffently in each class.

   8.Abstract classes and pure virtual functions - The abstractEnemy class has is an abstract class which includes the virtual function stats() which must be implemented to every enemy down the inheritance chain

   9.Initializer list - The enemy class constructor and also the character class constructor has an initializer list

   10.Dynamic and static dispatch - In C++ dynamic dispatch is implemented by using virtual function I have an example of this in the updateScreen() method
                                - Static dispatch can be found in various areas any method I have not made virtual is essentially static binded
 */

 /*
   Final KeyNotes
   -Superenemy will spawn randomly but if you wish to test it place a crawler and a venom enemy in a room directly across from each other example I used B for venom and C for crawler
   -To complete the game find the key located in room D and make your way back to J. If you try to enter G without a key you will not be able to enter
   -If you run out of stamina or health you will loose the game
  */

Game::Game() :
    player("Hero"),c("crawler",40,70),s("slime",20,50),v("venom",50,70),st("statueman",70,0),vs("superVenomCrawler",0,0)
{
    srand(time(nullptr));

    // Commands
    EventManager::getInstance().listen("go",        new GoListener(this));
    EventManager::getInstance().listen("map",       new MapListener(this));
    EventManager::getInstance().listen("info",      new InfoListener(this));
    EventManager::getInstance().listen("restart",   new RestartListener(this));
    EventManager::getInstance().listen("teleport",  new TeleportListener(this));
    EventManager::getInstance().listen("exit",      new ExitListener(this));
    EventManager::getInstance().listen("take",      new takelistener(this));
    EventManager::getInstance().listen("attack",    new attackListener(this));

    // State changes
    EventManager::getInstance().listen("characterDeath", new CharacterDeathListener(this));
    EventManager::getInstance().listen("enterRoom",      new EnterRoomListener(this));
    EventManager::getInstance().listen("victory",        new VictoryListener(this));
    EventManager::getInstance().listen("defeat",         new DefeatListener(this));
    EventManager::getInstance().listen("curse",         new damagelistener(this));

    rooms.push_back(new Room("A")); // 0
    rooms.push_back(new Room("B")); // 1
    rooms.push_back(new Room("C")); // 2
    rooms.push_back(new Room("D")); // 3
    rooms.push_back(new Room("E")); // 4
    rooms.push_back(new Room("F")); // 5
    rooms.push_back(new Room("G")); // 6
    rooms.push_back(new Room("H")); // 7
    rooms.push_back(new Room("I")); // 8
    rooms.push_back(new Room("J")); // 9
    rooms.push_back(new Room("Z")); //10 **This is where you go when you die rip
    rooms.push_back(new Room("T"));

    //                 N         E         S         W
    rooms[0]->setExits(rooms[4], rooms[2], rooms[7], rooms[1]);
    rooms[1]->setExits(nullptr,  rooms[0], nullptr,  nullptr);
    rooms[2]->setExits(nullptr,  nullptr,  nullptr,  rooms[0]);
    rooms[3]->setExits(nullptr,  rooms[4], nullptr,  nullptr);
    rooms[4]->setExits(nullptr,  rooms[5], rooms[0], rooms[3]);
    rooms[5]->setExits(nullptr,  nullptr,  nullptr,  rooms[4]);
    rooms[6]->setExits(nullptr,  rooms[7], nullptr,  nullptr);
    rooms[7]->setExits(rooms[0], rooms[8], rooms[9], rooms[6]);
    rooms[8]->setExits(nullptr,  nullptr,  nullptr,  rooms[7]);
    rooms[9]->setExits(rooms[7], nullptr,  nullptr,  nullptr);
    rooms[10]->setExits(rooms[11],nullptr,nullptr,nullptr);
    rooms[11]->setExits(nullptr,rooms[10],nullptr,nullptr); //These rooms trap the enemys in an endless loop of doom
    reset();


}

void Game::reset(bool show_update)
{
    //pointers to enemies
    enemy *crawler = &c;
    enemy *slime = &s;
    enemy *statueman = &st;
    enemy *venom = &v;
    enemy *venomSuper = &vs;

    //set game over to false
    gameOver = false;

    //pickup variables back to true
    pickerP = true;
    pickerC = true;
    pickerK = true;
    pickerG = true;

    //reset enemy stats
    statueman->setHealth(70);
    venom->setHealth(50);
    crawler->setHealth(40);
    venomSuper->setHealth(0);

    //set the rooms of the enemies
    statueman->setCurrentRoom(rooms[3]);
    crawler->setCurrentRoom(rooms[2]);
    venom->setCurrentRoom(rooms[4]);
    slime->setCurrentRoom(rooms[5]);
    venomSuper->setCurrentRoom(rooms[10]);

    //set up player for the new game
    player.setCurrentRoom(rooms[0]);
    player.removeAllItems();
    player.Setter(100 , "stamina");
    player.Setter(100 , "health");

    //title screen of the game
    cout<<player.getName()<<endl;
    cout << "Welcome to Zork!" << endl;

    if (show_update)
    {
        update_screen();
    }
}

void Game::setOver(bool over)
{
    this->gameOver = over;
}


char Game::roomToChar(string s)
{
   int n = s.length();
   char char_array[n + 1];
   strcpy(char_array, s.c_str());
   return char_array[0];
}



void Game::map()
{
   //week 5 lab
    enemy *crawler = &c;
    enemy *slime = &s;
    enemy *statueman = &st;
    enemy *venom = &v;
    enemy *venomSuper = &vs;

    char map[7][12] = {{' ','D',' ','-',' ','E',' ','-',' ','F',' '},
                       {' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '},
                       {' ','B',' ','-',' ','A',' ','-',' ','C',' '},
                       {' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '},
                       {' ','G',' ','-',' ','H',' ','-',' ','I',' '},
                       {' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ',' ','J',' ',' ',' ',' ',' '}}; //convert map to 2d array

       for(int i = 0; i < 7; i++){
           for(int j = 0; j < 12; j++){ //loops through array

              if(roomToChar(player.getCurrentRoom()->getName()) == map[i][j+1])//if char in room name is the same as the map position 1 ahead
              {
                   map[i][j+2] = ']'; //add this to the position 2 ahead
                   map[i][j] = '[';  //add this to the position 1 ahead
              }
              if(roomToChar(statueman->getCurrentRoom()->getName()) == map[i][j+1])
              {
                   map[i][j+2] = '!';
                   map[i][j] = '!';
              }
              if(roomToChar(slime->getCurrentRoom()->getName()) == map[i][j+1])
              {
                   map[i][j+2] = '!';
                   map[i][j] = '!';
              }
              if(roomToChar(crawler->getCurrentRoom()->getName()) == map[i][j+1])
              {
                   map[i][j+2] = '!';
                   map[i][j] = '!';
              }
              if(roomToChar(venom->getCurrentRoom()->getName()) == map[i][j+1])
              {
                   map[i][j+2] = '!';
                   map[i][j] = '!';
              }
              if(roomToChar(venomSuper->getCurrentRoom()->getName()) == map[i][j+1])
              {
                   map[i][j+2] = '*';
                   map[i][j] = '*';
              }

             std::cout << map[i][j];
           }
            std::cout << std::endl;
       }
       cout << "[player]" << " "<<"!enemy!" << " "<< "*superEnemy*"<< endl;
}

void Game::info()
{
    cout << "Available commands:" << endl;
    cout << " - go <direction>"   << endl;
    cout << " - teleport"         << endl;
    cout << " - map"              << endl;
    cout << " - info"             << endl;
    cout << " - take <item>"      << endl;
    cout << " - attack"           << endl;//adds the take command to the info menu
    cout <<"Warning be carful if venom and a crawler meet the will combine to create a super enemy"<<endl;
}

void Game::take(string item) //lab 4 assignment take command
{

    if(player.getCurrentRoom()->roomContainsItem(item) == 1) { //if room contains item
        /*These are boolean variables which allow the game to
          recognise if the player has picked up an item otherwise
          a the room will add duplicate Items
        */
         pickerP = true;
         pickerC = true;
         pickerK = true;
         pickerG = true;
         if(item == "potion") //if the item is potion
         {
              player.Setter(player.getStamina() + 10 , "stamina");
              player.Setter(player.getHealth() + 10 , "health");
              player.getCurrentRoom()->isItemInRoom(item);
              player.addCItem(new Item("potion"));
              pickerP = false; //set the boolean to false to stop adding duplicates to the room

              //if potion is picked up use unary operator overloading to take 1 away from enemys health
              -c;                                                                                         //<--unary operator overloading used here
              -s;
              -st;
              -v;
              -vs;
         }
         if(item == "curse")
         {
             cout<<"Ouch dont touch that"<< endl;
             player.getCurrentRoom()->isItemInRoom(item);
             player.addCItem(new Item("curse"));
             pickerC = false;
             EventManager::getInstance().trigger("curse", &player); //Event to hurt the player when cursed item is obtained
         }
         if(item == "key")
         {
             cout<<"use this key to get into the room J" << endl;
             player.addCItem(new Item("key"));
             player.getCurrentRoom()->isItemInRoom(item);
             pickerK = false;

         }
    }
    else {
       cout << "This item is not in the room" << endl;
   }
}

string Game::randomDirection() //week 5 assignment allows enemys to move in random directions
{
    string direction = "";
    int random = rand() % 4;

    if(random == 0){direction = "west";  return direction;}
    if(random == 1){direction = "south"; return direction;}
    if(random == 2){direction = "north"; return direction;}
    if(random == 3){direction = "east";  return direction;}
    return NULL;
}

void Game::moveEnemy(enemy *a) //method to move the enemy around the map
{
    Room * p = a->getCurrentRoom()->getExit(randomDirection());
    if (p != nullptr){ a->setCurrentRoom(p); a->setStamina(a->getStamina() - 5);}
    else{moveEnemy(a);}
}

void Game::superEnemy()
{
    if(c.getCurrentRoom() == v.getCurrentRoom()){
        enemy temp = c + v;                                                                 //<-- binary operator overloading used here
        vs.setCurrentRoom(c.getCurrentRoom());
        vs.setName(temp.getName());
        vs.setHealth(temp.getHealth());
        vs.setStamina(temp.getStamina());
        c.setCurrentRoom(rooms[10]);
        v.setCurrentRoom(rooms[11]);
        cout << "**warning**  a venom and a crawler have been combined to create a superVenomCrawler"<<endl;
       }
}

void Game::attack() //attack command for week 5 assignment
{
    enemy *crawler = &c;
    enemy *slime = &s;
    enemy *statueman = &st;
    enemy *venom = &v;
    enemy *supervenom = &vs;

    cout << "bam"<<endl;
    if(statueman->getCurrentRoom() == player.getCurrentRoom())
    {
        int boulderDamage = (rand() % 60)+1;
        statueman->setHealth(statueman->getHealth() - 50);
        player.Setter(player.getHealth() - 5, "health");
        cout <<"The statueMan has hit you = "<<boulderDamage<<endl;
        cout << endl;
        if(statueman->getHealth() <= 0){
            cout<<"you have defeated statue man" << endl;
            statueman->setCurrentRoom(rooms[10]);
        }

    }
    if(slime->getCurrentRoom() == player.getCurrentRoom())
    {
        int slimeSpit = 0;
        if(slime->getStamina() >= 20)
        {
           slimeSpit = (rand() % 10)+ 1;
        }
        else
        {
           slimeSpit = (rand() % 10)+ 1;
        }

        slime->setHealth(slime->getHealth() - 50);
        player.Setter(player.getHealth() - slimeSpit, "health");
        cout <<"The slimy has hit you = "<<slimeSpit << endl;
        cout << endl;
        if(slime->getHealth() <= 0){
            cout<<"you have defeated slimy" << endl;
            slime->setCurrentRoom(rooms[10]);
        }

    }
    if(crawler->getCurrentRoom() == player.getCurrentRoom())
    {
        int crawlerBite = 0;
        if(crawler->getStamina() >= 60)
        {
           crawlerBite = (rand() % 40)+ 1;
        }
        else
        {
           crawlerBite = (rand() % 20)+ 1;
        }
        crawler->setHealth(crawler->getHealth() - 50);
        player.Setter(player.getHealth() - crawlerBite, "health");
        cout <<"The crawler has hit you = "<<crawlerBite <<endl;
        cout << endl;
        if(crawler->getHealth() <= 0){
            cout<<"you have defeated crawler" << endl;
            crawler->setCurrentRoom(rooms[10]);
        }

    }
    if(venom->getCurrentRoom() == player.getCurrentRoom())
    {
        int poison = 0;
        if(venom->getStamina() >= 60)
        {
           poison = (rand() % 5)+ 1;
        }
        else
        {
           poison = (rand() % 2)+ 1;
        }

        venom->setHealth(venom->getHealth() - 50);
        player.Setter(player.getHealth() - poison, "health");
        cout <<"The venom has poisoned you = "<<poison <<endl;
        cout << endl;
        if(venom->getHealth() <= 0){
            cout<<"you have defeated venom" << endl;
            venom->setCurrentRoom(rooms[10]);
        }

    }
    if(supervenom->getCurrentRoom() == player.getCurrentRoom())
    {
        int poison = (rand() % 60)+ 1;
        venom->setHealth(supervenom->getHealth() - 7);
        player.Setter(player.getHealth() - poison, "health");
        cout <<"The superVenomCrawler biting you = "<<poison <<endl;
        cout << endl;
        if(supervenom->getHealth() <= 0){
            cout<<"you have defeated superVenom" << endl;
            supervenom->setCurrentRoom(rooms[10]);
        }
    }
}

void Game::go(string direction) //lab 4 assignment edit for key
{
   enemy *crawler = &c;
   enemy *slime = &s;
   enemy *venom = &v;
   enemy *superV = &vs;
   Room *next = player.getCurrentRoom()->getExit(direction);

    if (next != nullptr && next != rooms[9])
        {
        /*
         * The following allow the enemy to move only when the player moves which is why they are called in the go method(lab 5)
         */
        moveEnemy(crawler);
        moveEnemy(slime);
        moveEnemy(venom);
        moveEnemy(superV);

        player.setCurrentRoom(next);
        player.Setter(player.getStamina() - 5.6 , "stamina");

        EventManager::getInstance().trigger("enterRoom", next);
        }
        //the room locker
       else if(next == rooms[9] && player.boolBagContains("key") == true) //if the player has a key in the inventory allow the player to enter the room
        {
        player.setCurrentRoom(next);
        player.Setter(player.getStamina() - 1 , "stamina");
        EventManager::getInstance().trigger("enterRoom", next);
        }

       else if(next == rooms[9] && player.boolBagContains("key") == false) //if the player does not contain a key in the inventory print the following
        {
            cout << "get the key to complete the game"<< endl;
        }
     else {
        cout << "You hit a wall" << endl;
    }
}

void Game::teleport()
{
    int selected = rand() % rooms.size();

    player.setCurrentRoom(rooms[selected]);
    player.Setter(player.getStamina() - 45.5 , "stamina");

    EventManager::getInstance().trigger("enterRoom", rooms[selected]);
}

bool Game::is_over()
{
    return gameOver;
}

Character &Game::getPlayer()
{
    return player;
}

void Game::Hurt()
{
    player.Setter(player.getHealth() - 10,"health");
}

void Game::update_screen()
{
    enemy *crawler = &c;
    enemy *slime = &s;
    enemy *statueman = &st;
    enemy *venom = &v;
    enemy *supervenom = &vs;

    if (!gameOver) {
        Room *currentRoom = player.getCurrentRoom();

        cout << endl;
        cout << "You are in " << currentRoom->getName() << endl;
        cout << "Exits:";

        if (currentRoom->getExit("north") != nullptr) { cout << " north"; }
        if (currentRoom->getExit("east")  != nullptr) { cout << " east";  }
        if (currentRoom->getExit("south") != nullptr) { cout << " south"; }
        if (currentRoom->getExit("west")  != nullptr) { cout << " west";  }

        //The following adds the items in the room
        if (currentRoom->getName() == "A")
        {
            if(pickerP == true && currentRoom->roomContains("potion") == 0){currentRoom->addItem(new Item("potion"));}
        }                                                                           //add potion
        if (currentRoom->getName() == "E")
        {
            if(pickerC == true && currentRoom->roomContains("curse") == 0){currentRoom->addItem(new Item("curse"));}
        }                                                                          //add cursed
        if (currentRoom->getName() == "D")
        {
            if(pickerK == true && currentRoom->roomContains("key") == 0){currentRoom->addItem(new Item("key"));}
        }                                                                           //add Key

        cout << endl;
        cout << currentRoom->displayItem() << endl;
        cout << endl;

        superEnemy(); //activates the superenemy

        /*
         * the following are examples of dynamic binding encounter enemy is a virtual function which is used to tell the compiler
         * perform dynamic linkage
         */
        crawler->encouterEnemy(player);
        slime->encouterEnemy(player);
        statueman->encouterEnemy(player);
        venom->encouterEnemy(player);
        supervenom->encouterEnemy(player);
        /*
         * These call the enemy methods superEnemy(To check if enemys have combined)
         * Also encounter enemy which checks if the enemy has been encoutered by the player(lab 5)
         */


        cout << "Player Stats" <<" : " <<"HP: " << player.getHealth() << " ST: " << player.getStamina() << endl;
    }
    else {
        cout << "Type \"restart\" or \"exit\"." << endl;
    }

}

Game::~Game(){
    cout<<"Destructor has been called" << endl;
}
