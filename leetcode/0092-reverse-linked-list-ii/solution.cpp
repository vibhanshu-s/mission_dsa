class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* leftp = prev->next;
        ListNode* rightp = leftp;

        for (int i = left; i < right; i++)
            rightp = rightp->next;

        ListNode* temp = rightp->next;
        rightp->next = nullptr;

        prev->next = reverseList(leftp);
        leftp->next = temp;

        return dummy.next;
    }
};
