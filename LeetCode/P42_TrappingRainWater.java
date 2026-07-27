/*
 * LeetCode 42 - Trapping Rain Water
 * https://leetcode.com/problems/trapping-rain-water/
 *
 * Approach: Two Pointers (left, right) tracking leftMax and rightMax
 * Time  : O(n)
 * Space : O(1)
 */

public class P42_TrappingRainWater {

    public int trap(int[] height) {
        if (height == null || height.length == 0) {
            return 0;
        }

        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = Math.max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = Math.max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        P42_TrappingRainWater sol = new P42_TrappingRainWater();

        int[] height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        System.out.println(sol.trap(height1)); // 6

        int[] height2 = {4, 2, 0, 3, 2, 5};
        System.out.println(sol.trap(height2)); // 9
    }
}
