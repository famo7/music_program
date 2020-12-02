// Filename: MenuItem.h

// Written by: Farhan Mohamed

// Created date: 02/29/2020

// Last modified: 02/29/2020

/* Description: Header file containing the class definition for MenuItem class
 * helper class for Menu class
*/
#include <string>

using std::string;


#ifndef DT019G_MENUITEM_H
#define DT019G_MENUITEM_H


class MenuItem {
private:
    // data members
    string menuText;
    bool option;

public:
    // constructors
    MenuItem();

    MenuItem(string text, bool opt);

    // set methods
    void setMenuText(string text);

    void setOption(bool opt);

    // get methods
    bool getOption() const;

    string getMenuText() const;


};


#endif //DT019G_MENUITEM_H
