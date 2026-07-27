/*
 * LeetCode 503 - Next Greater Element II
 * https://leetcode.com/problems/next-greater-element-ii/
 *
 * Approach: Monotonic decreasing stack, iterate over the array twice
 *           (2n loop) to simulate circular behavior.
 * Time  : O(n)
 * Space : O(n)
 */

import java.util.*;

public class P503_NextGreaterElementII {

    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);
        Deque<Integer> stack = new ArrayDeque<>(); // stores indices

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while (!stack.isEmpty() && nums[stack.peek()] < num) {
                result[stack.pop()] = num;
            }
            if (i < n) {
                stack.push(i);
            }
        }
        return result;
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        P503_NextGreaterElementII sol = new P503_NextGreaterElementII();

        int[] nums = {1, 2, 1};
        System.out.println(Arrays.toString(sol.nextGreaterElements(nums))); // [2, -1, 2]
    }
}
