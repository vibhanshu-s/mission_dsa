/*
 * LeetCode 703 - Kth Largest Element in a Stream
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/
 *
 * Approach: Maintain a min-heap of size k. The top of the heap is always
 *           the kth largest element seen so far.
 * Time  : O(log k) per add()
 * Space : O(k)
 */

import java.util.PriorityQueue;

public class P703_KthLargestElementInStream {

    static class KthLargest {
        private final int k;
        private final PriorityQueue<Integer> minHeap;

        public KthLargest(int k, int[] nums) {
            this.k = k;
            this.minHeap = new PriorityQueue<>();
            for (int num : nums) {
                add(num);
            }
        }

        public int add(int val) {
            minHeap.offer(val);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
            return minHeap.peek();
        }
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        KthLargest kthLargest = new KthLargest(3, new int[]{4, 5, 8, 2});
        System.out.println(kthLargest.add(3));  // 4
        System.out.println(kthLargest.add(5));  // 5
        System.out.println(kthLargest.add(10)); // 5
        System.out.println(kthLargest.add(9));  // 8
        System.out.println(kthLargest.add(4));  // 8
    }
}
