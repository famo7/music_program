// Filename: Song.cpp

// Written by: Farhan Mohamed

// Created date: 02/27/2020

// Last modified: 02/27/2020

/* Description: Cpp file containing default constructor and definitions of member functions for Song header
 * some operator overloading and getters and setters.
*/

#include "Constants.h"
#include "Song.h"

Song::Song() {
    // default constructor.
    title = "";
    artist = "";
}

void Song::setTitle(string t) {
    title = t;
}

void Song::setArtist(string a) {
    artist = a;
}

void Song::setTime(myTime t) {
    time = t;
}

Song::Song(string t, string a, myTime ti) {
    title = t;
    artist = a;
    time = ti;
}

string Song::getTitle() const {
    return title;
}

string Song::getArtist() const {
    return artist;
}

myTime Song::getTime() const {
    return time;
}


ostream &operator<<(ostream &os, const Song &s) {
    // format: title|artist|time
    os << s.getTitle() << DELIM << s.getArtist() << DELIM << s.getTime();
    return os;
}

istream &operator>>(istream &is,  Song &s) {
    myTime t;
    string temp;

    getline(is, temp, DELIM);
    s.setTitle(temp);

    getline(is, temp, DELIM);
    s.setArtist(temp);

    is >> t;
    s.setTime(t);

    return is;
}

