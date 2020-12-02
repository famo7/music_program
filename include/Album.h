// Filename: Album.h

// Written by: Farhan Mohamed

// Created date: 02/28/2020

// Last modified: 02/28/2020

/* Description: Header file containing the class definition for Album class
 * contains name and vector of songs as data members.
 * also overloaded << >> streams and < for comparison of time.
*/
#include "Song.h"
#include <string>
#include <vector>
using std::string; using std::vector;

#ifndef DT019G_ALBUM_H
#define DT019G_ALBUM_H


class Album {
    private:
    // data members.
        string name;
        vector<Song> songs;
    public:
        // add songs to vector and setname.
        void addSong(const Song& song);
        void setName(string n);
        void clearSongs();

        // returns the vector.
        vector<Song> getSongs();
        // getname
        string getName() const;
        // total time in sec.
        int getTotalTime();
    // overload operator <
    bool operator<(Album &a);
};

// overloaded << and >> operators for reading and writing to/from file.
ostream &operator<<(ostream &os,  Album &t);
istream &operator>>(istream &is, Album &t);

#endif //DT019G_ALBUM_H
