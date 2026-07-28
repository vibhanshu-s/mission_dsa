#include <bits/stdc++.h>
using namespace std;

class P42_TrappingRainWater {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int left = 0, right = (int) height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};

int main() {
    P42_TrappingRainWater sol;

    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(height1) << "\n";

    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << sol.trap(height2) << "\n";

    return 0;
}
