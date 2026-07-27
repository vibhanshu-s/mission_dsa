/*
 * LeetCode 496 - Next Greater Element I
 * https://leetcode.com/problems/next-greater-element-i/
 *
 * Approach: Monotonic decreasing stack + HashMap
 * Time  : O(n + m)
 * Space : O(n)
 */

import java.util.*;

public class P496_NextGreaterElementI {

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> nextGreater = new HashMap<>();
        Deque<Integer> stack = new ArrayDeque<>();

        for (int num : nums2) {
            while (!stack.isEmpty() && stack.peek() < num) {
                nextGreater.put(stack.pop(), num);
            }
            stack.push(num);
        }

        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            result[i] = nextGreater.getOrDefault(nums1[i], -1);
        }
        return result;
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        P496_NextGreaterElementI sol = new P496_NextGreaterElementI();

        int[] nums1 = {4, 1, 2};
        int[] nums2 = {1, 3, 4, 2};
        System.out.println(Arrays.toString(sol.nextGreaterElement(nums1, nums2))); // [-1, 3, -1]
    }
}
