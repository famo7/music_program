// Filename: Jukebox.h

// Written by: Farhan Mohamed

// Created date: 03/02/2020

// Last modified: 03/08/2020

/*
 *
*/
#include "MenuItem.h"
#include "Album.h"
#include "Menu.h"
#include "Queue.h"
#include <Constants.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <thread>

using std::vector; using std::cout; using std::endl; using std::cin;
using std::ofstream; using std::ifstream;
using std::setw;

#ifndef DT019G_JUKEBOX_H
#define DT019G_JUKEBOX_H


class Jukebox {
    private:
        // all methods are private, only run and
        // default constructor is public.
        vector<Album> albums;
        Menu menu;
        Queue playList;
        void addAlbum();
        static string convertToUpper(const string &s);
        static bool helperSortName(const Album &a, const Album &b);
        void deleteAlbum();
        int searchAlbum(const string& name);
        void file();
        void printOneAlb(Album& a);
        void open();
        void save();
        void print();
        void printOneAlbum();
        void printSortedByAlbName();
        void sortByTotalTime();
        void printSortedAlbumNames();
        void printSortedByAlbTime();
        void play();
        void createPlayList();
        void randomize();
        void playTheList();
        string formatTime(int h, int m, int s);
        vector<Song> playListSongs();


    public:
        Jukebox();
        void run();
};


#endif //DT019G_JUKEBOX_H
