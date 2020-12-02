// Filename: Menu.cpp

// Written by: Farhan Mohamed

// Created date: 03/01/2020

// Last modified: 03/01/2020

/* Description: Cpp file containing default constructor and definitions of member functions for Menu header
 * some  getters and setters.
 * printing and  menuChoice methods.
*/


#include <limits>
#include "Menu.h"

using std::cout; using std::cin; using std::endl;

Menu::Menu() {
    heading = "";
}

Menu::Menu(string h) {
    heading = h;
}

void Menu::addItem(string menuText, bool enabled) {
    MenuItem item(menuText, enabled);
    menuItems.push_back(item);
}

void Menu::setHeading(string h) {
    heading = h;
}

void Menu::printMenuItems() {
    // output heading for jukebox later.
    cout << "**** " << heading <<  " ****" << endl;
    // prints menu with choice numbers from 1 up to Vector.size.
    int choice = 1;
    for (const auto &i: menuItems) {
        if (i.getOption()) {
            // print menutext
            cout << choice << ".   " << i.getMenuText() << endl;
        } else {
            // if option is false print menutext and with the text
            // disabled.
            cout << choice << ".   " << i.getMenuText() << " (Disabled)" <<
                 endl;
        }
        choice++;
    }
}

string Menu::getHeading() const {
    return heading;
}

int Menu::getMenuChoice() {
    // gives user input and returns the input if its valid else
    // returns -1.
    int choice = 0;
    cout << "Select a choice." << endl;
    cin >> choice;
    if (choice < 1 || choice > menuItems.size()) {
        // checking if choice is 1 - menuItem.size.
        cout << "invalid choice" << endl;
        choice = -1;
    }
    if (cin.fail()) {
        // checking if cin failed.
        cout << "Input cannot be other than a number." << endl;
        // clear buffer.
        cin.clear();
        // ignore rest of the line after first error.
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice = -1;
    }
    cin.ignore();
    // else choice is the user input.
    return choice;


}

vector<MenuItem> Menu::getMenuItems() {
    return menuItems;
}

void Menu::enableAll() {
    for(auto & menuItem : menuItems){
        menuItem.setOption(true);
    }
}



