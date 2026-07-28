#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

int substrings(string n) {
    const long long MOD = 1000000007LL;

    long long dpPrev = 0;
    long long answer = 0;

    for (int i = 0; i < (int) n.size(); i++) {
        long long digit = n[i] - '0';
        long long dpCurrent = (dpPrev * 10 + digit * (i + 1)) % MOD;
        answer = (answer + dpCurrent) % MOD;
        dpPrev = dpCurrent;
    }

    return (int) answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
