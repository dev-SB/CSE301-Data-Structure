//
// Created by Shubham Bhandari on 02-05-2018.
//
template<typename t>
class Stack {
private:
    int top = -1;
    int sizeStack;
                  
    t array[5];
public:

    Stack();

    Stack(int size);

    bool push(t value);

    bool pop();

    t peek();

    bool isEmpty();

    int size();

    bool isFull();
};

template<typename t>
Stack<t>::Stack() {}

template<typename t>
Stack<t>::Stack(int size) {
    sizeStack = size;
   // array[size];
}

template<typename t>
bool Stack<t>::push(t value) {
    if (isFull()) {
        return false;
    } else {
        top++;
        array[top] = value;
        return true;
    }
}

template<typename t>
bool Stack<t>::pop() {
    if (isEmpty()) {
        return false;
    } else {
        top--;
        return true;
    }
}

template<typename t>
int Stack<t>::size() { return ++top; }

template<typename t>
t Stack<t>::peek() { return array[top]; }

template<typename t>
bool Stack<t>::isEmpty() {
    if (top == -1)return true;
    else {
        return false;
    }
}

template<typename t>
bool Stack<t>::isFull() {
    if (top == sizeStack - 1) {
        return true;
    } else {
        return false;
    }
}



