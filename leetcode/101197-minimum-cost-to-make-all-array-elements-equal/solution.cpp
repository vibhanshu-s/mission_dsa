class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        vector<int> L(n),R(n);
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]) L[i]=L[i-1];
            else L[i]=i;
        }
        for(int i=n-1;i>=0;i--){
            if(i<n-1 && nums[i+1]==nums[i]) R[i]=R[i+1];
            else R[i]=i;
        }
        for(int i=1;i<n-1;i++){
            ans = min(ans,(long long)(L[i]+(n-1-R[i]))*nums[i]);
        }
        return ans;
    }
};
