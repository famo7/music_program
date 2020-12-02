// Filename: Queue.h

// Written by: Farhan Mohamed

// Created date: 03/01/2020

// Last modified: 03/08/2020

/* Description: Header file containing the class definition for Queue class
 * class that handles queue of songs.
*/

#include "Song.h"
#include <cstddef>
#include <iostream>
#include <iomanip>

using std::cout; using std::setw; using std::endl;

#ifndef DT019G_QUEUE_H
#define DT019G_QUEUE_H


class Queue {
private:
    // song pointer.
    Song *ptr;
    // size of queue.
    size_t size;
    // first and last elements of queue
    size_t last, first;

public:
    // default constructor and destructor.
    Queue();
    // copy constructor
    Queue(const Queue &q);
    // destructor.
    ~Queue();
    // public methods for the queue.
    bool isEmpty();
    bool isFull();
    void enQueue(const Song& s);
    bool deQueue();
    size_t getFirst() const{return first;}
    size_t getLast() const {return last;}
    Song* getSongs() const { return ptr;}


};


#endif //DT019G_QUEUE_H
