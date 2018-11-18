// listQ.cpp - implements queue as linked list
// Scott Matsubara
//11-17-2018

#include "listQ.h"

Queue::Queue() {front=0, rear=0, size=0;}  // IMPLEMENT CONSTRUCTOR

Queue::~Queue() {
  rear=0;
  size=0;
  while(front!=0){
    node* x=front;
    front=front->next;
    delete x;
  } 
}

void Queue::enqueue(int n) {
  node* new_node=new node(n);
  if(isEmpty()){
    rear=new_node;
    front=new_node;
  }
  else{
    rear->next=new_node;
    rear=new_node;
  }
  size++;
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();
    int value=front->data;
    node* x=front;
    front=front->next;
    delete x;
    size--;
    if(isEmpty())
      rear=0;
    return value;
}

void Queue::clear() {
  rear=0;
  size=0;
  while(front!=0){
    node* x=front;
    front=front->next;
    delete x;
  }
}

bool Queue::isEmpty() const {
  if (size==0)
    return true;
  return false;
}

int Queue::getSize() const {
  return size;
}
