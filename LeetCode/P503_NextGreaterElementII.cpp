#include <bits/stdc++.h>
using namespace std;

class P503_NextGreaterElementII {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> result(n, -1);
        stack<int> stk;

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while (!stk.empty() && nums[stk.top()] < num) {
                result[stk.top()] = num;
                stk.pop();
            }
            if (i < n) {
                stk.push(i);
            }
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
    P503_NextGreaterElementII sol;

    vector<int> nums = {1, 2, 1};
    cout << toString(sol.nextGreaterElements(nums)) << "\n";

    return 0;
}
