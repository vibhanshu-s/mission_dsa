/*
 * LeetCode 232 - Implement Queue using Stacks
 * https://leetcode.com/problems/implement-queue-using-stacks/
 *
 * Approach: Two stacks - "inStack" for pushes, "outStack" for pops/peeks.
 *           Transfer elements from inStack to outStack only when outStack
 *           is empty (amortized O(1)).
 * Time  : Amortized O(1) for push/pop/peek
 * Space : O(n)
 */

import java.util.Stack;

public class P232_ImplementQueueUsingStacks {

    static class MyQueue {
        private final Stack<Integer> inStack;
        private final Stack<Integer> outStack;

        public MyQueue() {
            inStack = new Stack<>();
            outStack = new Stack<>();
        }

        public void push(int x) {
            inStack.push(x);
        }

        public int pop() {
            transferIfNeeded();
            return outStack.pop();
        }

        public int peek() {
            transferIfNeeded();
            return outStack.peek();
        }

        public boolean empty() {
            return inStack.isEmpty() && outStack.isEmpty();
        }

        private void transferIfNeeded() {
            if (outStack.isEmpty()) {
                while (!inStack.isEmpty()) {
                    outStack.push(inStack.pop());
                }
            }
        }
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        MyQueue queue = new MyQueue();
        queue.push(1);
        queue.push(2);
        System.out.println(queue.peek());  // 1
        System.out.println(queue.pop());   // 1
        System.out.println(queue.empty()); // false
    }
}
