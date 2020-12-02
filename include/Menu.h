// Filename: Menu.h

// Written by: Farhan Mohamed

// Created date: 03/01/2020

// Last modified: 03/01/2020

/* Description: Header file containing the class definition for Menu class
 * contains vector of menuItems and a header.
*/

#include <iostream>
#include "MenuItem.h"
#include <vector>

using std::vector;

#ifndef DT019G_MENU_H
#define DT019G_MENU_H


class Menu {
private:
    // data members.
    vector<MenuItem> menuItems;
    string heading;

public:
    // default constructor
    Menu();
    // constructor with param
    explicit Menu(string h);
    // to add item to menuItems
    void addItem(string menuText, bool enabled);
    // getter for getting heading.
    string getHeading() const;
    // set, print and menu choice methods below.
    void setHeading(string h);

    void enableAll();

    void printMenuItems();

    int getMenuChoice();

    vector<MenuItem> getMenuItems();

};


#endif //DT019G_MENU_H
