#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool needed[26] = {};

        for (int i = 0; i < n / 2; ++i) {
            char low = min(s[i], s[n - 1 - i]);
            char high = max(s[i], s[n - 1 - i]);

            for (char c = low + 1; c <= high; ++c)
                needed[c - 'a'] = true;
        }

        cout << count(begin(needed), end(needed), true) << '\n';
    }

    return 0;
}
