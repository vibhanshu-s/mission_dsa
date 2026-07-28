#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;

        if (b < 0 && a > 1) {
            cout << 0 << "\n";
            continue;
        }

        long long value = 1;
        if (a > 1) {
            for (long long i = 0; i < b; i++) {
                value *= a;
            }
        }

        long long lower = (value / x) * x;
        long long upper = lower + x;

        if (value - lower <= upper - value) {
            cout << lower << "\n";
        } else {
            cout << upper << "\n";
        }
    }

    return 0;
}
