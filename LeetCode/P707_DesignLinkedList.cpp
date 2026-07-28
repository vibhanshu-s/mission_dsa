#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    Node* dummy;
    int size;

public:
    MyLinkedList() {
        dummy = new Node(-1);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node* cur = dummy->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        index = max(index, 0);

        Node* prev = dummy;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node* prev = dummy;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        prev->next = prev->next->next;
        size--;
    }
};

int main() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);
    cout << list.get(1) << "\n";
    list.deleteAtIndex(1);
    cout << list.get(1) << "\n";
    return 0;
}
