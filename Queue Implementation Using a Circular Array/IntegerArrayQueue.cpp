#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value) {
    // compute the index of the next position in the circular array
    int nextBack = (back + 1) % size;
    cout << "nextBack: " << nextBack << endl;
    // check if the queue is full
    if (back == front-1) {
        cout << "Queue is full, unable to enqueue " << value << " at position " << nextBack << endl;
        return false; // queue is full
    }
    // add the value to the back of the queue
    array[nextBack] = value;
    cout << "Enqueued " << value << " at position " << nextBack << endl;
    // move the back index to the next position in the circular array
    back = nextBack;
    // if the front index is -1 (indicating an empty queue), set it to 0
    if (front == -1) {
        front = 0;
    }
    return true; // enqueue successful
}

int IntegerArrayQueue::dequeue() {
    // check if the queue is empty
    if (front == back) {
        return 0; // queue is empty
    }
    // get the value at the front of the queue
    int value = array[front];
    // move the front index to the next position in the circular array
    front = (front + 1) % size;
    return value; // dequeue successful
}
