#include "item.h"

Item::Item(string inDescription) {
    description = inDescription;
}

Item::Item()
{

}

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}


