// Filename: MenuItem.cpp

// Written by: Farhan Mohamed

// Created date: 02/29/2020

// Last modified: 02/29/2020

/* Description: Cpp file containing default constructor and definitions of member functions for MenuItem header
 * some  getters and setters.
*/

#include "MenuItem.h"

MenuItem::MenuItem() {
    // default constructor
    menuText = "";
    option = false;
}

MenuItem::MenuItem(string text, bool opt) {
    //constructor with parameters.
    menuText = text;
    option = opt;
}

void MenuItem::setMenuText(string text) {
    // set menu text
    menuText = text;
}

void MenuItem::setOption(bool opt) {
    // set option for enabling or disabling
    option = opt;
}

bool MenuItem::getOption() const {
    // get option
    return option;
}

string MenuItem::getMenuText() const {
    // get menu text
    return menuText;
}




