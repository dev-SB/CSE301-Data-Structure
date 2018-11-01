//
// Created by Shubham Bhandari on 19-07-2018.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <bits/stdc++.h>

using namespace std;

template<class t>
class Queue {
private:
    int front, rear, length;
    t *q;
public:
    Queue();

    Queue(int length);

    void enqueue(t val);

    t dequeqe();

    int size();

    bool isEmpty();

    bool isFull();

    t top();

    void display();

};


#endif //QUEUE_QUEUE_H
