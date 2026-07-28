#include <bits/stdc++.h>
using namespace std;

class P141_LinkedListCycle {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    P141_LinkedListCycle sol;

    P141_LinkedListCycle::ListNode* n1 = new P141_LinkedListCycle::ListNode(3);
    P141_LinkedListCycle::ListNode* n2 = new P141_LinkedListCycle::ListNode(2);
    P141_LinkedListCycle::ListNode* n3 = new P141_LinkedListCycle::ListNode(0);
    P141_LinkedListCycle::ListNode* n4 = new P141_LinkedListCycle::ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    cout << boolalpha << sol.hasCycle(n1) << "\n";

    P141_LinkedListCycle::ListNode* a = new P141_LinkedListCycle::ListNode(1);
    P141_LinkedListCycle::ListNode* b = new P141_LinkedListCycle::ListNode(2);
    a->next = b;
    cout << boolalpha << sol.hasCycle(a) << "\n";

    return 0;
}
