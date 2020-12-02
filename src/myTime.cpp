// Filename: myTime.cpp

// Written by: Farhan Mohamed

// Created date: 02/27/2020

// Last modified: 02/27/2020

/* Description: Cpp file containing constructors and definitions of member functions for myTime header
 * some operator overloading and getters and setters.
*/


#include "myTime.h"

myTime::myTime() {
    hour = 0;
    minute = 0;
    seconds = 0;
}
myTime::myTime(int h, int m, int s) {
    hour = h;
    minute = m;
    seconds = s;
}
void myTime::setHour(int h) {
    hour = h;
}

void myTime::setMinutes(int m) {
    minute = m;
}

void myTime::setSeconds(int s) {
    seconds = s;
}

int myTime::getHours() const {
    return hour;
}

int myTime::getMinutes() const {
    return minute;
}

int myTime::getSeconds() const {
    return seconds;
}

myTime myTime::operator+(const myTime &t) {
    // temp time object.
    myTime tempTime;
    //t.sec + seconds is temptime.seconds.
    tempTime.seconds=seconds+t.seconds;
    // minute is minute + t.minute and seconds/60.
    tempTime.minute=minute+t.minute+(tempTime.seconds/60);
    // same for hour
    tempTime.hour=hour+t.hour+(tempTime.minute/60);
    // mod 60 for minutes and seconds. to restart after 60.
    tempTime.minute=tempTime.minute%60;
    tempTime.seconds=tempTime.seconds%60;
    // return tempobject.
    return tempTime;

}

bool myTime::operator<(const myTime &t) {
    // converting the objects to seconds and comparing them.
    return ((hour*3600) + (minute*60) + seconds) < ((t.hour*3600) +
            (t.minute*60) + t.seconds);
}

bool myTime::operator==(const myTime &t) {
    // comparing  data members if they are ==
    return hour == t.hour && minute == t.minute && seconds == t.seconds;
}



ostream &operator<<(ostream &os, const myTime &t) {
    // totalsec is total sec of hour, minute and seconds.
    int totalSec = t.getSeconds() + (t.getMinutes()*60) + (t.getHours()*3600);
    os << totalSec;
    return os;
}

istream &operator>>(istream &is,  myTime &t) {
    // converting back to hour, minutes.
    int secs;
    is >> secs;
    t.setHour(secs/3600);
    secs %=3600;
    t.setMinutes(secs/60);
    secs%=60;
    t.setSeconds(secs);

    return is;
}



