class Solution {
public:
    int minRange(int a, int b, int c) {
        int mx = max({a, b, c});
        int mn = min({a, b, c});
        int mid = a + b + c - mx - mn;
        return min(mx - mn, mid);
    }
};
