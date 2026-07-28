#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void transferIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transferIfNeeded();
        int value = outStack.top();
        outStack.pop();
        return value;
    }

    int peek() {
        transferIfNeeded();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << "\n";
    cout << q.pop() << "\n";
    cout << boolalpha << q.empty() << "\n";
    return 0;
}
