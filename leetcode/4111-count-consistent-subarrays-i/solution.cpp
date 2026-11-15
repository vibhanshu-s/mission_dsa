class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int l = 0; l < n; l++) {
            int a = nums[l], mn = nums[l];
            for (int r = l; r < n; r++) {
                a &= nums[r];
                mn = min(mn, nums[r]);
                if (a == mn) ans++;
            }
        }
        return ans;
    }
};
