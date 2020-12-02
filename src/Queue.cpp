// Filename: Queue.cpp

// Written by: Farhan Mohamed

// Created date: 03/01/2020

// Last modified: 03/08/2020

/* Description: Cpp file containing default constructor and definitions of member functions for Queue header
 *  operator overloading and some methods for the queue.
*/

#include "Queue.h"

Queue::Queue() {
    // the queue is empty when object is created
    first = last = -1;
    // size is 5 at start and increase as needed later.
    size = 5;
    // ptrs size is 5 initially.
    ptr = new Song[size];


}



Queue::~Queue() {
    // we delete the allocated mem in destructor.
    delete[] ptr;
}

bool Queue::isEmpty() {
    // -1 represent empty queue.
    // if firs == last then queue is also empty.
    return (first == -1 && last == -1) || first == last;
}

void Queue::enQueue(const Song &s) {
    // if queue is empty.
    if (isEmpty()) {
        // then both first and last will be 0
        first = last = 0;
        // add to add song to element 0 and increment last.
        ptr[last] = s;
        last++;
        // if the queue is full.
    } else if (isFull()) {
        // increase the size with 5
        size += 5;
        // create temporary array with the new size.
        Song *tempArr = new Song[size];
        for (int i = 0; i < size - 5; i++) {
            // copy all elements from ptr array to temp array.
            tempArr[i] = ptr[i];
        }
        // deallocate old ptr
        delete[] ptr;
        // create new one with the new size.
        ptr = new Song[size];
        for (int i = 0; i < size - 5; i++) {
            // copy values from temp array to ptr arr.
            ptr[i] = tempArr[i];
        }
        // delete temp array.
        delete[] tempArr;
        // add song to ptr in last element and increment element.
        ptr[last] = s;
        last++;
    } else {
        // else we just add and increment last.
        ptr[last] = s;
        last++;

    }
}


bool Queue::isFull() {
    // if last == size-1 then the arr is full.
    return size == last;
}

bool Queue::deQueue() {
    // to dequeue we check if the queue is empty
    // if it is we return false
    if (isEmpty()) {
        return false;
        // if first == last then they are empty
        // both become -1. and return true.
    }else if(first == last){
        first = last = -1;
        return true;
    }else {
        // else we increment first which discards the value.
        // and return true.
        first++;
        return true;
    }
}

Queue::Queue(const Queue &q) {
    // copy constructor.
        // copy everything from q queue to this.
        ptr = new Song[q.size];
        size = q.size;
        first = q.first;
        last = q.last;
        for (int i = 0; i < q.size; i++) {
            ptr[i] = q.ptr[i];
    }
}




