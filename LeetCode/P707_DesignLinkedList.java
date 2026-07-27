/*
 * LeetCode 707 - Design Linked List
 * https://leetcode.com/problems/design-linked-list/
 *
 * Approach: Singly linked list with a dummy head node and a size counter.
 * Time  : O(k) for get/insert/delete at index k, O(1) for addAtHead
 * Space : O(n)
 */

public class P707_DesignLinkedList {

    static class MyLinkedList {
        private class Node {
            int val;
            Node next;
            Node(int val) {
                this.val = val;
            }
        }

        private final Node dummy; // dummy head, dummy.next is the real head
        private int size;

        public MyLinkedList() {
            dummy = new Node(-1);
            size = 0;
        }

        public int get(int index) {
            if (index < 0 || index >= size) {
                return -1;
            }
            Node cur = dummy.next;
            for (int i = 0; i < index; i++) {
                cur = cur.next;
            }
            return cur.val;
        }

        public void addAtHead(int val) {
            addAtIndex(0, val);
        }

        public void addAtTail(int val) {
            addAtIndex(size, val);
        }

        public void addAtIndex(int index, int val) {
            if (index > size) {
                return;
            }
            index = Math.max(index, 0);

            Node prev = dummy;
            for (int i = 0; i < index; i++) {
                prev = prev.next;
            }
            Node newNode = new Node(val);
            newNode.next = prev.next;
            prev.next = newNode;
            size++;
        }

        public void deleteAtIndex(int index) {
            if (index < 0 || index >= size) {
                return;
            }
            Node prev = dummy;
            for (int i = 0; i < index; i++) {
                prev = prev.next;
            }
            prev.next = prev.next.next;
            size--;
        }
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        MyLinkedList list = new MyLinkedList();
        list.addAtHead(1);
        list.addAtTail(3);
        list.addAtIndex(1, 2);   // list: 1 -> 2 -> 3
        System.out.println(list.get(1)); // 2
        list.deleteAtIndex(1);   // list: 1 -> 3
        System.out.println(list.get(1)); // 3
    }
}
