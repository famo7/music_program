// Filename: Jukebox.cpp

// Written by: Farhan Mohamed

// Created date: 03/02/2020

// Last modified: 03/02/2020

/*
 *
*/



#include "Jukebox.h"

Jukebox::Jukebox() {
    // initializing menu here.
    menu.addItem("File...", true);
    menu.addItem("Add an album", true);
    menu.addItem("Delete an album", false);
    menu.addItem("Print...", false);
    menu.addItem("Play...", false);
    menu.addItem("Exit", true);


}

void Jukebox::addAlbum() {
    // objects and variables for the album and songs.
    Album album;
    Song song;
    myTime t;
    string albumName, songName, songArtist;
    int h, m, s;

    // user input.
    cout << "Enter the album name: ";
    getline(cin, albumName);
    // if the search is -1 then it does not exist
    // so we can add.
    int exists = searchAlbum(albumName);

    if (exists == -1) {
        // input, output and setting object data.
        cout << endl;
        album.setName(albumName);
        cout << "Enter song name: ";
        cout << endl;
        getline(cin, songName);
        song.setTitle(songName);
        cout << "Enter song artist: ";
        cout << endl;
        getline(cin, songArtist);
        song.setArtist(songArtist);
        cout << "Enter duration of the song in hour: ";
        cin >> h;
        cout << "Enter minutes :";
        cin >> m;
        cout << "Enter seconds: ";
        cin >> s;
        cout << endl;
        cin.ignore();
        t.setHour(h);
        t.setMinutes(m);
        t.setSeconds(s);
        song.setTime(t);
        album.addSong(song);
        // adding to albums.
        albums.push_back(album);
    } else {
        // else the album exists.
        cout << "The album already exists" << endl;
    }
}

void Jukebox::deleteAlbum() {
    string input;
    // checking if the option is  not enabled.
    if (!menu.getMenuItems()[2].getOption()) {
        // error message.
        cout << "Menu option is disabled!!" << endl;
    } else {
        // if its enabled then we get input.
        cout << "Enter the album to delete: ";
        getline(cin, input);
        // search.
        int index = searchAlbum(input);
        if (index == -1) {
            // if not found.
            cout << "Did not find album " << input << endl;
        } else {
            // else we delete the album.
            string name = albums[index].getName();
            // delete using index.
            albums.erase(albums.begin() + index);
            // success message.
            cout << "succesfully deleted " << name << endl;
        }
    }

}

void Jukebox::run() {
    // clear console.
    system("cls");
    // set heading.
    menu.setHeading("Jukebox");

    bool again = true;
    do {
        // print menu and get choice as long as the
        // user does not enter 6.
        // and call the appropriate method.
        menu.printMenuItems();
        switch (menu.getMenuChoice()) {
            case 1:
                file();
                break;
            case 2:
                addAlbum();
                break;
            case 3:
                deleteAlbum();
                break;
            case 4:
                print();
                break;
            case 5:
                play();
                break;
            case 6:
                again = false;
                break;
        }
    } while (again);


}

void Jukebox::open() {
    // when we choose file and open.
    Album tempAlbum;
    if (!albums.empty()) {
        // clear album it items are present.
        albums.clear();
    } else {
        // else create istream object.
        ifstream file(REALFILE);
        if (file.is_open()) {
            // if file is open, read from file to temp album
            while (file >> tempAlbum) {
                // add temp album to albums.
                albums.push_back(tempAlbum);
            }
            // message for success.
            cout << "Loaded from " << REALFILE << " succesfully" << endl;
            // close file.
            file.close();
        } else {
            // else could not open file.
            cout << "Could not open file." << endl;
        }
    }

}

void Jukebox::save() {
    // to save the loaded data, we save it to another file.
    // not the original.
    ofstream file(SAVETOFILE);
    if (file.is_open()) {
        // if file is open
        for (auto i: albums) {
            // read from albums and save it in the file names
            // SAVETOFILE.
            file << i << endl;
        }
        // success message.
        cout << "Saved to file name: " << SAVETOFILE <<
             " succesfully" << endl;
        // close file.
        file.close();
    } else {
        // error message if file not open
        cout << "Could not open file." << endl;
    }
}

void Jukebox::file() {
    // creating filemenu.
    Menu fileMenu;
    // set heading.
    fileMenu.setHeading("FILE");
    // add menu choices(items).
    fileMenu.addItem("Open", true);
    fileMenu.addItem("Save", true);
    fileMenu.addItem("Back to main menu", true);

    // clear console.
    system("cls");
    // taking input and calling appropriate function
    bool again = true;
    do {
        // print fileMenu and get choice if choice is 1
        // we enable all choices.
        fileMenu.printMenuItems();
        switch (fileMenu.getMenuChoice()) {
            case 1:
                menu.enableAll();
                open();
                break;
            case 2:
                save();
                break;
            case 3:
                // if we exit, clear console.
                system("cls");
                again = false;
                break;
        }
    } while (again);
}


void Jukebox::print() {
    // check if menu choice print is not enabled.
    if (!menu.getMenuItems()[3].getOption()) {
        cout << "Menu option is disabled!!!" << endl;
    } else {
        // if its enables we setheading, add items and
        // loop.
        Menu printMenu;
        printMenu.setHeading("PRINT");
        printMenu.addItem("Print one album", true);
        printMenu.addItem("Print all sorted by album name", true);
        printMenu.addItem("Print all sorted by album total time", true);
        printMenu.addItem("Print simple sorted by album name", true);
        printMenu.addItem("Print simple sorted by album total time", true);
        printMenu.addItem("Back to main menu", true);

        // taking input and calling appropriate function
        bool again = true;
        do {
            // while again is true(choice is not 6).
            // printMenu, get choice and call appropriate method.
            printMenu.printMenuItems();
            switch (printMenu.getMenuChoice()) {
                case 1:
                    printOneAlbum();
                    break;
                case 2:
                    printSortedByAlbName();
                    break;
                case 3:
                    sortByTotalTime();
                    break;
                case 4:
                    printSortedAlbumNames();
                    break;
                case 5:
                    printSortedByAlbTime();
                    break;
                case 6:
                    system("cls");
                    again = false;
                    break;
            }
        } while (again);
    }


}

void Jukebox::printOneAlbum() {
    // print one album if search is success.
    cout << "Enter album name: ";
    string albumName;
    getline(cin, albumName);
    int searchResult = searchAlbum(albumName);
    if (searchResult == -1) {
        cout << "The album does not exist" << endl;
    } else {
        printOneAlb(albums[searchResult]);
    }
}


string Jukebox::convertToUpper(const string &s) {
    // converts string to uppercase and returns it.
    string toUpperCase = s;
    for (int i = 0; i < s.size(); ++i) {
        // every char
        toUpperCase[i] = toupper(toUpperCase[i]);
    }
    return toUpperCase;
}

int Jukebox::searchAlbum(const string &name) {
    // search using parameter name if found we return the
    // index else we return -1.
    int index = -1;

    if (albums.empty()) {
        index = -1;
    } else {
        for (int i = 0; i < albums.size(); i++) {
            if (convertToUpper(name) == convertToUpper(albums[i].getName())) {
                index = i;
                break;
            } else {
                index = -1;
            }
        }
    }

    return index;
}


void Jukebox::printSortedByAlbName() {
    // sort album using helper method, helperSort.
    sort(albums.begin(), albums.end(), helperSortName);
    // print albums sorted by name.
    for (auto &album : albums) {
        cout << setw(50) << album.getName() << endl;
        printOneAlb(album);
        cout << endl;
    }
}

bool Jukebox::helperSortName(const Album &a, const Album &b) {
    // compare 2 objects and return bool for sort funtion.
    return convertToUpper(a.getName()) < convertToUpper(b.getName());
}

void Jukebox::printOneAlb(Album &a) {

    // gets object as parameter and prints the
    // object in right format.
    for (const auto &i: a.getSongs()) {
        string timeFormat = formatTime(i.getTime().getHours(),
                                       i.getTime().getMinutes(),
                                       i.getTime().getSeconds());
        cout << "Song name: " << std::left << setw(50) << i.getTitle()
             << "Artist: " << std::left << setw(15) << i.getArtist()
             << "Time: " << std::left << setw(20) << timeFormat << endl;

    }
}

void Jukebox::sortByTotalTime() {
    // sort by total time in descending order using lambda expression.
    std::sort(albums.begin(), albums.end(),
              [](Album &a, Album &b) { return a.getTotalTime() > b.getTotalTime(); });

    for (auto &album : albums) {
        // print the sorted albums.
        cout << setw(50) << album.getName() << endl;
        printOneAlb(album);
        cout << endl;
    }
}

void Jukebox::printSortedAlbumNames() {
    // sort using HelperSortName method.
    sort(albums.begin(), albums.end(), helperSortName);

    // print only name of album.
    cout << "Album names sorted " << endl << endl;
    for (auto &album : albums) {
        cout << album.getName() << endl;
    }
}

void Jukebox::printSortedByAlbTime() {
    // sort by total time using lambda expression, and print
    // album name and total time.
    std::sort(albums.begin(), albums.end(),
              [](Album &a, Album &b) { return a.getTotalTime() > b.getTotalTime(); });
    for (auto &album : albums) {
        cout << setw(0) << "Album name: " << std::left
             << setw(50) << album.getName();
        cout << setw(0) << "Total time: " << std::left << setw(10)
             << album.getTotalTime() << endl;
        cout << endl;
    }
}

void Jukebox::play() {
    if (!menu.getMenuItems()[4].getOption()) {
        // check if option is disabled.
        cout << "Menu option disabled" << endl;
    } else {
        // else create new play menu.
        Menu play;
        // set heading.
        play.setHeading("PLAY");
        // add options.
        play.addItem("Create a playlist from songs", true);
        play.addItem("Create a random list", true);
        play.addItem("Play list", true);
        play.addItem("Back to main menu", true);

        bool again = true;
        do {
            // print menu items, get menu choice call appropriate method.
            // while not 4(exit.).
            play.printMenuItems();
            switch (play.getMenuChoice()) {
                case 1:
                    createPlayList();
                    break;
                case 2:
                    randomize();
                    break;
                case 3:
                    playTheList();
                    break;
                case 4:
                    again = false;
                    break;

            }
        } while (again);

    }
}

void Jukebox::createPlayList() {
    // empty the playlist if not empty.
    while (!playList.isEmpty()) {
        playList.deQueue();
    }
    // else output with right format.
    // count start from one, which will be displayed.
    int count = 1;
    cout << endl << endl;
    cout << std::left << setw(5) << "No." << std::left << setw(55)
         << "Title" << std::left << setw(25) << "Artist"
         << std::left << setw(25) << "Length" << endl;
    cout << "=============================================="
            "============================================="
         << endl;
    for (auto &album: albums) {
        for (const auto &song: album.getSongs()) {
            string timeFormat = formatTime(song.getTime().getHours(),
                                           song.getTime().getMinutes(),
                                           song.getTime().getSeconds());
            cout << std::left << setw(5) << count;
            cout << std::left << setw(55) << song.getTitle();
            cout << std::left << setw(25) << song.getArtist();
            cout << std::left << setw(25) << timeFormat << endl;

            count++;
        }


    }
    // get user input.
    cout << "Please enter your playList. use ',' as your deliminator"
         << "ex 2, 10, 1 or 6,14,20" << " : ";
    string input;
    getline(cin, input);
    // delete all spaces from the string.
    input.erase(std::remove(input.begin(), input.end(), ' '),
                input.end());

    // string stream.
    std::stringstream ss(input);
    // vector for the string containing comma and numbers.
    vector<int> playListVec;
    // read the numbers into i.
    for (int i; ss >> i;) {
        // put the numbers into the vector.
        playListVec.push_back(i);
        // if there is , ignore it.
        if (ss.peek() == ',')
            ss.ignore();
    }
    // get all songs available from playList songs method.
    vector<Song> s = playListSongs();
    // loop the vectors.
    for (auto i: playListVec) {
        // enqueue songs but i -1, because the songs vector
        // starts from 0 and the count starts from 1.
        playList.enQueue(s[i - 1]);
        cout << "Added song " << i << " To the playlist" << endl;
    }
    // message.
    cout << "Playlist was created." << endl;
}


void Jukebox::randomize() {
    // get all songs availabel in album.
    vector<Song> allSongs = playListSongs();
    // shuffle the songs.
    random_shuffle(allSongs.begin(), allSongs.end());
    // if playList is not empty.
    while (!playList.isEmpty()) {
        // empty it.
        playList.deQueue();
    }
    // user input.
    cout << "How many songs do you want in your playlist? ";
    int input;
    cin >> input;
    // enqueue the amount of songs the user input. and get it
    // from the begining of the vector.
    for (int i = 1; i <= input; i++) {
        playList.enQueue(allSongs[i]);
    }

}

void Jukebox::playTheList() {
    // time to wait is 3 secs.
    std::chrono::seconds t(3);
    // use copy constructor to copy from playlist to tempQ.
    Queue tempQ(playList);
    if (!tempQ.isEmpty()) {
        // if tempQ is not empty.
        for (int i = tempQ.getFirst(); i < tempQ.getLast(); i++) {
            // out put song title and artist.
            cout << "Title: " << std::left << setw(40) << tempQ.getSongs()[i].getTitle()
                 << "By " << std::left << setw(20) << tempQ.getSongs()[i].getArtist()
                 << endl;
            // sleep for 3 secs.
            std::this_thread::sleep_for(t);
            // dequeue the tempQ.
            tempQ.deQueue();
        }
        if (tempQ.isEmpty()) {
            // message when the songs played.
            cout << "Playlist ended! use option 3 to play your list again." << endl;
        }
    } else {
        // else user did not create a playlist.
        cout << "Playlist is empty, Create playlist first." << endl;
    }


}


string Jukebox::formatTime(int h, int m, int s) {
    // function that formats time and returns a string.
    // hour, minute and second get formated individially and
    // added to format string later.
    string hour, minute, second;
    string format;
    if (h <= 0) {
        // if there is no hours, we add minute and seconds formated.
        minute += std::to_string(m);
        if (s < 10) {
            second += '0';
            second += std::to_string(s);
        } else {
            second += std::to_string(s);
        }
    } else {
        // if there is hour we add hour, minutes and seconds.
        hour += std::to_string(h);
        hour += ':';
        if (m < 10) {
            minute += '0';
            minute += std::to_string(m);
        } else {
            minute += std::to_string(m);
        }
        if (s < 10) {
            second += '0';
            second += std::to_string(s);
        } else {
            second += std::to_string(s);
        }
    }
    // return format.
    format += hour;
    format += minute += ':';
    format += second;
    return format;
}

vector<Song> Jukebox::playListSongs() {
    // create a vector of all songs available in albums and return it.
    vector<Song> s;
    for (auto &album: albums) {
        for (const auto &song: album.getSongs()) {
            s.push_back(song);
        }
    }
    return s;
}
















