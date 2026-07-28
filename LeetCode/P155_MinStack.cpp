#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> minStack;

public:
    MinStack() {
    }

    void push(int val) {
        stk.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        stk.pop();
        minStack.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << "\n";
    minStack.pop();
    cout << minStack.top() << "\n";
    cout << minStack.getMin() << "\n";
    return 0;
}
