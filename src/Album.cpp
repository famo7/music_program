// Filename: Album.cpp

// Written by: Farhan Mohamed

// Created date: 02/28/2020

// Last modified: 02/28/2020

/* Description: Cpp file containing definition of member functions.
 *
*/

#include "Album.h"
#include <iostream>
#include <sstream>

using std::endl;

void Album::addSong(const Song &song) {
    // method that adds a song to the vector.
    songs.push_back(song);
}

void Album::setName(string n) {
    // setting name.
    name = n;
}

string Album::getName() const {
    // return name
    return name;
}

bool Album::operator<(Album &a) {
    // comparing total time of songs. in album
    return getTotalTime() < a.getTotalTime();
}

int Album::getTotalTime() {
    // returns total seconds.
    int totalSeconds = 0;
    for (const auto &i: songs) {
        totalSeconds += i.getTime().getHours() * 3600;
        totalSeconds += i.getTime().getMinutes() * 60;
        totalSeconds += i.getTime().getSeconds();
    }
    return totalSeconds;
}

vector<Song> Album::getSongs() {
    // return songs in album(vector).
    return songs;
}

void Album::clearSongs() {
    songs.clear();
}


ostream &operator<<(ostream &os, Album &t) {
    // overloading << operator to write to file.
    int n = 1; // counter for songs.
    // write album name.
    os << t.getName() << endl;
    // song size
    os << t.getSongs().size() << endl;

    // get all songs in album
    for(const auto& i: t.getSongs()){
        if(n == t.getSongs().size()){
            // if its the last song, then no new line
            os << i;
        }else {
            // else with newline.
            os << i << endl;
        }
        n++;
    }
    return os;
}

istream &operator>>(istream &is, Album &t) {
    // overloading operator to read from file.
    // clear songs.
    t.clearSongs();
    // temp string for album name, size.
    string temp;
    // song obj for songs.
    Song s;
    int songSize, count = 0;
    // get the line with album and set it to album name
    getline(is, temp);
    t.setName(temp);
    // get the line store it in temp and convert it to integer
    getline(is, temp);
    std::stringstream ss(temp);
    ss >> songSize;

    // while count is less than the songs.
    while(count < songSize){
        is >> s;
        is.get();
        // add to songs.
        t.addSong(s);
        count++;
    }

    // return istream.
    return is;
}
