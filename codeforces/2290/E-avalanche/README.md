# 2290E. Avalanche

**Language:** C++23 (GCC 14-64, msys2) · **Group:** Contest 2290 · **Memory:** 12 KB · **Runtime:** 78 ms

[View on Codeforces](https://codeforces.com/contest/2290/problem/E)

> Accepted 2026-11-12 · synced automatically by CodeSync

## Problem

There are $n$ piles of stones in a row, numbered from $1$ to $n$ from left to right. The $i$-th pile contains $a_i$ stones. You are also given an integer $k$.

Alice and Bob play a game. They take turns, and Alice moves first. In one move, a player chooses a non-empty pile $i$ and removes one stone from it. Then one new stone is added to each pile $j$ such that $\max(1, i-k) \le j \le i-1$, that is, to each of the $\min(k, i-1)$ piles immediately to the left of pile $i$. If $i = 1$, no stones are added. The supply of new stones is unlimited. For example, if $i = 5$ and $k = 2$, one stone is added to each of piles $3$ and $4$.

The player who cannot make a move loses. It can be shown that the game always ends after a finite number of moves.

Determine the winner if both players play optimally.

Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2 \le n \le 2\cdot 10^5$, $1 \le k \le n-1$) — the number of piles and the parameter of the game.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the numbers of stones in the piles.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

Output

For each test case, print Alice if Alice wins, and Bob otherwise.

ExampleInput

```
52 11 13 20 0 14 10 0 1 05 21 2 3 4 53 12 5 2
```

Output

```
AliceBobAliceAliceBob
```

Note

In the first test case, $k = 1$ and each of the two piles contains one stone.

- If Alice takes the stone from the second pile, one stone is added to the first pile, so the piles contain $2$ and $0$ stones. Then Bob and Alice take one stone each from the first pile, and Bob cannot move.
- If Alice takes the stone from the first pile, Bob has to take the stone from the second pile, which adds a stone to the first pile. Alice takes it, and Bob cannot move.

In both cases, Alice wins.

In the second test case, $k = 2$, and Alice has to take the stone from the third pile. Then one stone is added to each of the first two piles, so the piles contain $1$, $1$, and $0$ stones.

- If Bob takes the stone from the second pile, a stone is added to the first pile, so the piles contain $2$, $0$, and $0$ stones. Then Alice and Bob take one stone each from the first pile, and Alice cannot move.
- If Bob takes the stone from the first pile, Alice has to take the stone from the second pile, which adds a stone to the first pile. Bob takes it, and Alice cannot move.

In both cases, Bob wins.

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
```
