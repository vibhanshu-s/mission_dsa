/*
 * LeetCode 295 - Find Median from Data Stream
 * https://leetcode.com/problems/find-median-from-data-stream/
 *
 * Approach: Two Heaps
 *   - maxHeap (lower half of numbers)
 *   - minHeap (upper half of numbers)
 * Time  : O(log n) per addNum(), O(1) for findMedian()
 * Space : O(n)
 */

import java.util.PriorityQueue;
import java.util.Collections;

public class P295_FindMedianFromDataStream {

    static class MedianFinder {
        private final PriorityQueue<Integer> maxHeap; // lower half
        private final PriorityQueue<Integer> minHeap; // upper half

        public MedianFinder() {
            maxHeap = new PriorityQueue<>(Collections.reverseOrder());
            minHeap = new PriorityQueue<>();
        }

        public void addNum(int num) {
            maxHeap.offer(num);
            minHeap.offer(maxHeap.poll());

            if (minHeap.size() > maxHeap.size()) {
                maxHeap.offer(minHeap.poll());
            }
        }

        public double findMedian() {
            if (maxHeap.size() > minHeap.size()) {
                return maxHeap.peek();
            }
            return (maxHeap.peek() + minHeap.peek()) / 2.0;
        }
    }

    // ---------- Simple manual test ----------
    public static void main(String[] args) {
        MedianFinder mf = new MedianFinder();
        mf.addNum(1);
        mf.addNum(2);
        System.out.println(mf.findMedian()); // 1.5
        mf.addNum(3);
        System.out.println(mf.findMedian()); // 2.0
    }
}
