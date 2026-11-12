# 2290B. Stubborn Pen

**Language:** C++23 (GCC 14-64, msys2) · **Group:** Contest 2290 · **Memory:** 24 KB · **Runtime:** 15 ms

[View on Codeforces](https://codeforces.com/contest/2290/problem/B)

> Accepted 2026-11-12 · synced automatically by CodeSync

## Problem

A pen can write in two colors: red and blue. Initially, the pen writes in red. Each time the pen writes a letter, its color switches automatically: after writing a red letter, it writes in blue, and after writing a blue letter, it writes in red.

Before writing each letter, including the first one, you may also switch the color of the pen manually: from red to blue or from blue to red.

You need to write a string $s$ of length $n$ consisting of the characters R and B. The letters are written one by one from left to right. The $i$-th letter must be written in red if $s_i = \texttt{R}$, and in blue if $s_i = \texttt{B}$.

Find the minimum number of manual switches needed to write the string.

Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the length of the string.

The second line of each test case contains the string $s$ of length $n$, consisting only of the characters R and B.

Output

For each test case, print a single integer — the minimum number of manual switches.

ExampleInput

```
55BRRBR1R4RBRB3BBB6RRBBRB
```

Output

```
20032
```

Note

In the first test case, $s = \texttt{BRRBR}$.

- Initially, the pen writes in red, but the first letter is blue, so the color is switched manually.
- After the blue letter, the pen switches to red by itself. This is the right color for the second letter.
- After that, the pen switches to blue by itself, but the third letter is red, so the color is switched manually a second time.
- The last two letters are written without manual switches.

So the answer is $2$.

In the third test case, the color switches by itself exactly as needed, so no manual switches are required.

In the fourth test case, the pen has the wrong color before each of the three letters: it is red at the start, and after each blue letter it switches to red by itself. So three manual switches are needed.

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

        int switches = (s[0] == 'B');
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) ++switches;
        }

        cout << switches << '\n';
    }
    return 0;
}
```
