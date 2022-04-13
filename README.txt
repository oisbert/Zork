
Compiled and tested on 3 different machines
/*Compile in repl.it
 1.To compile in repl.it
 2.Upload folder 
 3.Replace the main
 4.Click on the main again to refresh the file it it may take a minute to update the could in the main file
 5.Once this is complete run the "main" 
 6.It will take varios speed depending on your computer 
*/

/*Compile in QT
 1.To compile in QT
 2.extract the files from moodle 
 3.Make a new QT project
 4.Find where you made the QT project in file explorer 
 5.Copy the files from the moodle file into the QT project file folder 
 6.Go back into QT 
 7.Right click on the project name and click "Add existing files"
 8.Copy all the project files into QT "replace the main"
*/





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

