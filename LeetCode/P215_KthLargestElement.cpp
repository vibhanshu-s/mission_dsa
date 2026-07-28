#include <bits/stdc++.h>
using namespace std;

class P215_KthLargestElement {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if ((int) minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

int main() {
    P215_KthLargestElement sol;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << sol.findKthLargest(nums1, 2) << "\n";

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << sol.findKthLargest(nums2, 4) << "\n";

    return 0;
}
