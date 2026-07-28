#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if ((int) minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << "\n";
    cout << kthLargest.add(5) << "\n";
    cout << kthLargest.add(10) << "\n";
    cout << kthLargest.add(9) << "\n";
    cout << kthLargest.add(4) << "\n";
    return 0;
}
