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

        int switches = (s[0] == 'B');
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) ++switches;
        }

        cout << switches << '\n';
    }
    return 0;
}
