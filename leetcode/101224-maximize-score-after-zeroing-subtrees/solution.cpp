class Solution {
public:
    long long maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> ch(n);
        for (int i = 1; i < n; i++) ch[parent[i]].push_back(i);

        vector<int> order; order.reserve(n);
        order.push_back(0);
        for (int k = 0; k < (int)order.size(); k++)
            for (int c : ch[order[k]]) order.push_back(c);

        vector<long long> f(n);
        for (int k = n - 1; k >= 0; k--) {
            int v = order[k];
            if (ch[v].empty()) { f[v] = score[v]; continue; }
            long long S = 0, m = LLONG_MAX;
            for (int c : ch[v]) { S += f[c]; m = min(m, f[c]); }
            f[v] = score[v] + S - (op[v] == 1 ? m : min(0LL, m));
        }
        return f[0];
    }
};
