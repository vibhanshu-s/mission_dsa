/*
 * LeetCode 347 - Top K Frequent Elements
 * https://leetcode.com/problems/top-k-frequent-elements/
 *
 * Approach: Bucket Sort by frequency
 * Time  : O(n)
 * Space : O(n)
 */

import java.util.*;

public class P347_TopKFrequentElements {

    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            freqMap.merge(num, 1, Integer::sum);
        }

        // bucket[i] holds all numbers that appear exactly i times
        List<Integer>[] bucket = new List[nums.length + 1];
        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
            int freq = entry.getValue();
            if (bucket[freq] == null) {
                bucket[freq] = new ArrayList<>();
            }
            bucket[freq].add(entry.getKey());
        }

        List<Integer> result = new ArrayList<>();
        for (int i = bucket.length - 1; i >= 0 && result.size() < k; i--) {
            if (bucket[i] != null) {
                result.addAll(bucket[i]);
            }
        }

        return result.stream().mapToInt(Integer::intValue).limit(k).toArray();
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        P347_TopKFrequentElements sol = new P347_TopKFrequentElements();

        int[] nums1 = {1, 1, 1, 2, 2, 3};
        System.out.println(Arrays.toString(sol.topKFrequent(nums1, 2))); // [1, 2]

        int[] nums2 = {1};
        System.out.println(Arrays.toString(sol.topKFrequent(nums2, 1))); // [1]
    }
}
