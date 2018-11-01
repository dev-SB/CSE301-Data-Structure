//
// Created by Shubham Bhandari on 19-07-2018.
//

#include "Queue.h"

template<typename t>
Queue<t>::Queue() {}

template<typename t>
Queue<t>::Queue(int length) {
    front=0,rear=0;
    this->length = length;
    q=new t[this->length];
}

template<typename t>
int Queue<t>::size() { return this->rear-this->front;}

template<typename t>
bool Queue<t>::isEmpty() { return this->front==this->rear;}

template<typename t>
bool Queue<t>::isFull() {
    return this->rear == this->length;
}

template<typename t>
void Queue<t>::enqueue(t value) {
    if(!isFull()){
        q[rear]=value;
        rear++;
    }
}
template<typename t>
t Queue<t>::dequeqe() {
    //Two implementations: either remove a value and move front pointer
    //or keep front pointer static and move all the values from i to i-1 and decrease rear by one value
    //second implementaion:
    t val=-1;
    if(!isEmpty()){
        val=q[front];
        for(int i=front;i<rear;i++){
            q[i]=q[i+1];
        }
        rear--;
        return val;
    }
    return -1;
}

template <typename t>
t Queue<t>::top() { return q[front];}

template <typename t>
void  Queue<t>::display(){
    for(int i=front;i<rear;i++){
        cout<<q[i]<<" ";
    }

}



