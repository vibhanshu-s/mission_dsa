/*
 * LeetCode 142 - Linked List Cycle II
 * https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Approach: Floyd's Cycle Detection, then find entry point of the cycle.
 * Time  : O(n)
 * Space : O(1)
 */

public class P142_LinkedListCycleII {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;

        // Step 1: detect if a cycle exists
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                // Step 2: find entry point
                ListNode ptr = head;
                while (ptr != slow) {
                    ptr = ptr.next;
                    slow = slow.next;
                }
                return ptr;
            }
        }
        return null;
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        P142_LinkedListCycleII sol = new P142_LinkedListCycleII();

        // Build list: 3 -> 2 -> 0 -> -4 -> (back to 2)
        ListNode n1 = new ListNode(3);
        ListNode n2 = new ListNode(2);
        ListNode n3 = new ListNode(0);
        ListNode n4 = new ListNode(-4);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n2;

        ListNode entry = sol.detectCycle(n1);
        System.out.println(entry != null ? entry.val : "null"); // 2
    }
}
