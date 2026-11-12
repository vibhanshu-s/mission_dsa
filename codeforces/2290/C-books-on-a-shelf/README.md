# 2290C. Books on a Shelf

**Language:** C++23 (GCC 14-64, msys2) · **Group:** Contest 2290 · **Memory:** 5804 KB · **Runtime:** 62 ms

[View on Codeforces](https://codeforces.com/contest/2290/problem/C)

> Accepted 2026-11-12 · synced automatically by CodeSync

## Problem

There are $n$ books, and the height of the $i$-th book is $h_i$. You put all the books on a shelf in a row in any order you like.

A book is visible from the left if it is strictly taller than every book to its left. A book is visible from the right if it is strictly taller than every book to its right. In particular, the leftmost book is visible from the left, and the rightmost book is visible from the right.

Find the maximum possible number of books that are visible from at least one side, and any arrangement of the books with this number of visible books.

Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2\cdot 10^5$) — the number of books.

The second line of each test case contains $n$ integers $h_1, h_2, \ldots, h_n$ ($1 \le h_i \le 10^9$) — the heights of the books.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

Output

For each test case, print two lines.

In the first line, print a single integer $k$ — the maximum possible number of books that are visible from at least one side.

In the second line, print $n$ integers — the heights of the books from left to right in an arrangement in which exactly $k$ books are visible from at least one side. These $n$ integers must be the integers $h_1, h_2, \ldots, h_n$ in some order.

If there are several such arrangements, print any of them.

ExampleInput

```
561 2 2 3 3 31537 7 744 1 3 2113 1 4 1 5 9 2 6 5 3 5
```

Output

```
5
2 3 3 3 2 1
1
5
2
7 7 7
4
3 4 2 1
10
1 3 4 5 9 5 6 5 3 2 1
```

Note

In the first test case, in the arrangement $[2, 3, 3, 3, 2, 1]$, the first book of height $2$ and the first book of height $3$ are visible from the left. The book of height $1$, the last book of height $2$, and the last book of height $3$ are visible from the right. In total, $5$ books are visible.

In the third test case, the leftmost book is visible from the left and the rightmost book is visible from the right, but the middle book is visible from neither side.

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
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());

        vector<long long> left, middle, right;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) ++j;

            left.push_back(a[i]);           
            if (j - i >= 2) right.push_back(a[i]);
            for (int k = 2; k < j - i; ++k)
                middle.push_back(a[i]);     

            i = j;
        }

        reverse(right.begin(), right.end());

        int visible = static_cast<int>(left.size() + right.size());
        cout << visible << '\n';

        for (long long x : left) cout << x << ' ';
        for (long long x : middle) cout << x << ' ';
        for (long long x : right) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
```
