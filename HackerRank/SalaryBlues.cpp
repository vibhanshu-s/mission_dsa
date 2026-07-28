#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    long long minSalary = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (minSalary == -1 || a[i] < minSalary) {
            minSalary = a[i];
        }
    }

    long long g = 0;
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i] - minSalary);
    }

    while (q--) {
        long long k;
        cin >> k;

        cout << gcd(g, minSalary + k) << "\n";
    }

    return 0;
}
