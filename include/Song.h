// Filename: Song.h

// Written by: Farhan Mohamed

// Created date: 02/27/2020

// Last modified: 02/27/2020

/* Description: Header file containing the class definition for Song class
 * title, artist and myTime object.
 * also overloaded << >> streams.
*/

#include <string>
#include "myTime.h"

using std::string;

#ifndef DT019G_SONG_H
#define DT019G_SONG_H


class Song {
    private:
        string title;
        string artist;
        myTime time;
    public:
    // constructors.
        Song();
        Song(string t, string a, myTime ti);

        // set methods.
        void setTitle(string t);
        void setArtist(string a);
        void setTime(myTime t);

        // get methods.
        string getTitle() const;
        string getArtist() const;
        myTime getTime() const;
};
// overloading << and >> operators for reading/ writing to/from files.
ostream &operator<<(ostream &os, const Song &s);
istream &operator>>(istream &is, Song &s);


#endif //DT019G_SONG_H
