#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        // Only weight parity matters.
        vector<int> weightParity(n + 1);
        int windowParity = 0;
        int totalParity = 0;

        for (int i = 1; i <= n; ++i) {
            weightParity[i] = 1 ^ windowParity;

            if (a[i] % 2 == 1)
                totalParity ^= weightParity[i];

            windowParity ^= weightParity[i];
            if (i - k >= 1)
                windowParity ^= weightParity[i - k];
        }

        cout << (totalParity ? "Alice" : "Bob") << '\n';
    }

    return 0;
}
