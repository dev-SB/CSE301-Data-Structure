#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main() {

    int size;
    cout << "Enter size of Queue:";
    cin >> size;
    Queue<int> queue1 = Queue<int>(size);
    char input;
    cout << "e for Enqueue" << "\n" << "d for dequeue" << "\n" << "s for size" << "\n" << "f to check is full" << "\n"
         << "i for display" <<"\n"<< "m to check is empty" << "\n";
    cin >> input;
    while (input != 'q') {
        int val = 0;
        switch (input) {
            case 'e':
                cin >> val;
                queue1.enqueue(val);
                break;
            case 'd':
                cout<<queue1.dequeqe();
                break;
            case 's':
                cout << queue1.size();
                break;
            case 'f':
                cout << queue1.isFull();
                break;
            case 'm':
                cout << queue1.isEmpty();
                break;
            case 'i':
                queue1.display();
                break;
            default:
                cout << "d";
        }
        cin >> input;
    }

    return 0;
}