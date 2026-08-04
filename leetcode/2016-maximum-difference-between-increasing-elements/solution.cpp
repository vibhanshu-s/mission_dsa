class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int rightMax = nums[n-1];
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            int curr = nums[i];
            nums[i] = rightMax - curr;
            rightMax = max(rightMax,curr);
            ans = max(ans,nums[i]);
        }
        return ans>0?ans:-1;
    }
};
