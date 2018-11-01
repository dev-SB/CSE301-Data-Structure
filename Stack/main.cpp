#include <bits/stdc++.h>
#include "Stack.cpp"
using namespace std;
int main() {
Stack<int> n=Stack<int>(10);
    n.push(5);
    n.push(10);
cout<<n.isFull()<<endl;
    cout<<n.peek()<<endl;
    cout<<n.isEmpty()<<endl;
    cout<<n.pop()<<endl;
    cout<<n.peek()<<endl;
    cout<<n.size();
    return 0;
}