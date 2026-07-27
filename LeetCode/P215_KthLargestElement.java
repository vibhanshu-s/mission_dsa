/*
 * LeetCode 215 - Kth Largest Element in an Array
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 *
 * Approach: Min-Heap of size k
 * Time  : O(n log k)
 * Space : O(k)
 */

import java.util.PriorityQueue;

public class P215_KthLargestElement {

    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num : nums) {
            minHeap.offer(num);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }
        return minHeap.peek();
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        P215_KthLargestElement sol = new P215_KthLargestElement();

        int[] nums1 = {3, 2, 1, 5, 6, 4};
        System.out.println(sol.findKthLargest(nums1, 2)); // 5

        int[] nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        System.out.println(sol.findKthLargest(nums2, 4)); // 4
    }
}
