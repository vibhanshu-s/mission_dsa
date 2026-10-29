# 92. Reverse Linked List II

**Difficulty:** Medium · **Language:** C++ · **Memory:** 11.2 MB · **Runtime:** 0 ms

[View on LeetCode](https://leetcode.com/problems/reverse-linked-list-ii/)

**Tags:** `Linked List`

> Accepted 2026-10-29 · synced automatically by CodeSync

## Problem

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

**Example 1:**

 ![](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [5], left = 1, right = 1
Output: [5]
```

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `-500 <= Node.val <= 500`
- `1 <= left <= right <= n`

 **Follow up:** Could you do it in one pass?

## Solution

```cpp
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
```
