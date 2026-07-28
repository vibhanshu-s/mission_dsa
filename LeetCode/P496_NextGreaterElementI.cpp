#include <bits/stdc++.h>
using namespace std;

class P496_NextGreaterElementI {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> stk;

        for (int num : nums2) {
            while (!stk.empty() && stk.top() < num) {
                nextGreater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> result(nums1.size());
        for (size_t i = 0; i < nums1.size(); i++) {
            auto it = nextGreater.find(nums1[i]);
            result[i] = (it != nextGreater.end()) ? it->second : -1;
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
    P496_NextGreaterElementI sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    cout << toString(sol.nextGreaterElement(nums1, nums2)) << "\n";

    return 0;
}
