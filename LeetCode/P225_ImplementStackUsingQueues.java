/*
 * LeetCode 225 - Implement Stack using Queues
 * https://leetcode.com/problems/implement-stack-using-queues/
 *
 * Approach: Single queue; after each push, rotate the queue so the
 *           newly pushed element moves to the front.
 * Time  : O(n) push, O(1) pop/top
 * Space : O(n)
 */

import java.util.LinkedList;
import java.util.Queue;

public class P225_ImplementStackUsingQueues {

    static class MyStack {
        private final Queue<Integer> queue;

        public MyStack() {
            queue = new LinkedList<>();
        }

        public void push(int x) {
            queue.offer(x);
            // Rotate: move all elements before x to behind it
            int size = queue.size();
            for (int i = 0; i < size - 1; i++) {
                queue.offer(queue.poll());
            }
        }

        public int pop() {
            return queue.poll();
        }

        public int top() {
            return queue.peek();
        }

        public boolean empty() {
            return queue.isEmpty();
        }
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        MyStack stack = new MyStack();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.top());   // 2
        System.out.println(stack.pop());   // 2
        System.out.println(stack.empty()); // false
    }
}
