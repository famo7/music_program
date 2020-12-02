// Filename: myTime.h

// Written by: Farhan Mohamed

// Created date: 02/27/2020

// Last modified: 02/27/2020

/* Description: Header file containing the class definition for myTime class
 * contains hour, minute and seconds, constructor and
 * overloaded operators.
*/


#include <iostream>

using std::ostream; using std::istream;

#ifndef DT019G_TIME_H
#define DT019G_TIME_H


class myTime {
    private:
        int hour;
        int minute;
        int seconds;
    public:
    // constructors.
        myTime();
        myTime(int h, int m, int s);

        // setter methods.
        void setHour(int h);
        void setMinutes(int m);
        void setSeconds(int s);

        //getter methods.
        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;

        // overloaded operators.
    myTime operator+(const myTime &t);
    bool operator<(const myTime &t);
    bool operator==(const myTime &t);


};

// overloaded << and >> operators for reading and writing to/from file.
ostream &operator<<(ostream &os, const myTime &t);
istream &operator>>(istream &is, myTime &t);


#endif //DT019G_TIME_H
