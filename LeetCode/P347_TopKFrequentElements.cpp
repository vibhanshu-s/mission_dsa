#include <bits/stdc++.h>
using namespace std;

class P347_TopKFrequentElements {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& entry : freqMap) {
            int freq = entry.second;
            bucket[freq].push_back(entry.first);
        }

        vector<int> result;
        for (int i = (int) bucket.size() - 1; i >= 0 && (int) result.size() < k; i--) {
            for (int value : bucket[i]) {
                result.push_back(value);
            }
        }

        if ((int) result.size() > k) {
            result.resize(k);
        }
        return result;
    }
};

string toString(const vector<int>& arr) {
    ostringstream sb;
    sb << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        if (i > 0) {
            sb << ", ";
        }
        sb << arr[i];
    }
    sb << "]";
    return sb.str();
}

int main() {
    P347_TopKFrequentElements sol;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    cout << toString(sol.topKFrequent(nums1, 2)) << "\n";

    vector<int> nums2 = {1};
    cout << toString(sol.topKFrequent(nums2, 1)) << "\n";

    return 0;
}
