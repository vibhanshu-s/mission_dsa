#include <bits/stdc++.h>
using namespace std;

class P142_LinkedListCycleII {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

int main() {
    P142_LinkedListCycleII sol;

    P142_LinkedListCycleII::ListNode* n1 = new P142_LinkedListCycleII::ListNode(3);
    P142_LinkedListCycleII::ListNode* n2 = new P142_LinkedListCycleII::ListNode(2);
    P142_LinkedListCycleII::ListNode* n3 = new P142_LinkedListCycleII::ListNode(0);
    P142_LinkedListCycleII::ListNode* n4 = new P142_LinkedListCycleII::ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    P142_LinkedListCycleII::ListNode* entry = sol.detectCycle(n1);
    if (entry != nullptr) {
        cout << entry->val << "\n";
    } else {
        cout << "null" << "\n";
    }

    return 0;
}
