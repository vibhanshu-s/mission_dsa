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
        int n, k;
        cin >> n >> k;

        vector<long long> freq(k, 0);
        freq[0] = 1;

        long long running = 0;
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;

            running += val;
            int mod = running % k;

            answer += freq[mod];
            freq[mod]++;
        }

        cout << answer << "\n";
    }

    return 0;
}
