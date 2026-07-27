/*
 * LeetCode 141 - Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Approach: Floyd's Cycle Detection (Fast & Slow Pointers)
 * Time  : O(n)
 * Space : O(1)
 */

public class P141_LinkedListCycle {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        P141_LinkedListCycle sol = new P141_LinkedListCycle();

        // Build list: 3 -> 2 -> 0 -> -4 -> (back to 2)
        ListNode n1 = new ListNode(3);
        ListNode n2 = new ListNode(2);
        ListNode n3 = new ListNode(0);
        ListNode n4 = new ListNode(-4);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n2;

        System.out.println(sol.hasCycle(n1)); // true

        // No cycle case
        ListNode a = new ListNode(1);
        ListNode b = new ListNode(2);
        a.next = b;
        System.out.println(sol.hasCycle(a)); // false
    }
}
