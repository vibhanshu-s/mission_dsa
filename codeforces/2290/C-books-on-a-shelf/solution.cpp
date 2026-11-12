#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());

        vector<long long> left, middle, right;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) ++j;

            left.push_back(a[i]);           
            if (j - i >= 2) right.push_back(a[i]);
            for (int k = 2; k < j - i; ++k)
                middle.push_back(a[i]);     

            i = j;
        }

        reverse(right.begin(), right.end());

        int visible = static_cast<int>(left.size() + right.size());
        cout << visible << '\n';

        for (long long x : left) cout << x << ' ';
        for (long long x : middle) cout << x << ' ';
        for (long long x : right) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
