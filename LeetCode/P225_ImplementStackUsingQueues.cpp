#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        q.push(x);
        int size = (int) q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int value = q.front();
        q.pop();
        return value;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stk;
    stk.push(1);
    stk.push(2);
    cout << stk.top() << "\n";
    cout << stk.pop() << "\n";
    cout << boolalpha << stk.empty() << "\n";
    return 0;
}
