# 2290D. Letters Down

**Language:** C++23 (GCC 14-64, msys2) · **Group:** Contest 2290 · **Memory:** 508 KB · **Runtime:** 15 ms

[View on Codeforces](https://codeforces.com/contest/2290/problem/D)

> Accepted 2026-11-12 · synced automatically by CodeSync

## Problem

You are given a string $s$ of length $n$ consisting of lowercase Latin letters.

In one operation, you choose a lowercase Latin letter $x$ other than a and replace all occurrences of $x$ in $s$ (not just one) with the previous letter of the alphabet. For example, if $s = \texttt{bcab}$, an operation with $x = \texttt{c}$ turns it into bbab, and a subsequent operation with $x = \texttt{b}$ replaces all three letters b and turns it into aaaa. If $x$ does not occur in $s$, the operation does not change $s$.

Find the minimum number of operations needed to make $s$ a palindrome. A palindrome is a string that reads the same from left to right and from right to left.

Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2\cdot 10^5$) — the length of the string.

The second line of each test case contains the string $s$ of length $n$ consisting of lowercase Latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

Output

For each test case, print a single integer — the minimum number of operations needed to make $s$ a palindrome.

ExampleInput

```
54abca4abdc7racecar4cbad4zaza
```

Output

```
130225
```

Note

In the first test case, one operation with $x = \texttt{c}$ turns abca into the palindrome abba.

In the second test case, you can perform operations with $x = \texttt{d}$, $x = \texttt{c}$, and $x = \texttt{b}$: abdc $\to$ abcc $\to$ abbb $\to$ aaaa. The second operation changes both letters c, and the third operation changes all three letters b.

In the third test case, the string is already a palindrome.

In the fourth test case, you can perform operations with $x = \texttt{d}$ and $x = \texttt{b}$: cbad $\to$ cbac $\to$ caac.

In the fifth test case, the operations with $x = \texttt{z}, \texttt{y}, \ldots, \texttt{b}$ in this order turn zaza into aaaa.

## Solution

```cpp
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
```
