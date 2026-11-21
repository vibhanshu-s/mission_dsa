class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans(n);
        int a = 0, b = 0;
        for(int i=0;i<n;i++){
            if(i<n-1 && rain[i] && rain[i+1]){
                if(a<=b){ ans[i]="Alice"; a++; }
                else{ ans[i]="Bob"; b++; }
            }
            else if(rain[i]){ ans[i]="Bob"; b++; }
            else ans[i]="None";
        }
        return ans;
    }
};
