class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans = {};
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> freq(101,0);
        for(int i:nums) freq[i]++;
        for(int i=mini;i<=maxi;i++)
            if(freq[i]==0) ans.push_back(i);
        return ans;
    }
};
