// arrayQ.cpp - implements queue as array
// Scott Matsubara
//11-17-2018

#include "arrayQ.h"

Queue::Queue() {front=0, rear=0, size=0;}  // IMPLEMENT CONSTRUCTOR

void Queue::enqueue(int n) {
    if (isFull())
        throw FullQueue();
    if(isEmpty())
      data[rear]=n;
    else{
      rear=(rear+1)%CAPACITY;
      data[rear]=n;
    }
    size++;
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    front=(front+1)%CAPACITY;
    size--;

    // COMPLETE THIS IMPLEMENTATION
    return data[front]; // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
  front=0;
  rear=0;
  size=0;
}

bool Queue::isEmpty() const {
  if (size==0)
    return true;
  return false;
}

bool Queue::isFull() const {
  if(size==CAPACITY)
    return true;
  return false;
}

int Queue::getSize() const {
  return size;
}
