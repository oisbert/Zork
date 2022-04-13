#ifndef ITEM_H
#define ITEM_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

class Item
{
private:

    string longDescription;
    string description;

public:
    Item (string description);
    Item ();
    string getShortDescription();
    string getLongDescription();
    void testInheritance();
};

#endif // ITEM_H
