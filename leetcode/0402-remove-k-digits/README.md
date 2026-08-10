# 402. Remove K Digits

**Difficulty:** Medium · **Language:** C++ · **Memory:** 13.7 MB · **Runtime:** 15 ms

[View on LeetCode](https://leetcode.com/problems/remove-k-digits/)

**Tags:** `String`, `Stack`, `Greedy`, `Monotonic Stack`

> Accepted 2026-08-10 · synced automatically by CodeSync

## Problem

Given string num representing a non-negative integer `num`, and an integer `k`, return *the smallest possible integer after removing* `k` *digits from* `num`.

**Example 1:**

```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

**Example 2:**

```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

**Example 3:**

```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

**Constraints:**

- `1 <= k <= num.length <= 10^5`
- `num` consists of only digits.
- `num` does not have any leading zeros except for the zero itself.

## Solution

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> dq;
        string ans = "";

        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';

            while (!dq.empty() && k > 0 && dq.back() > digit) {
                dq.pop_back();
                k--;
            }

            dq.push_back(digit);
        }

        while (!dq.empty() && k > 0) {
            dq.pop_back();
            k--;
        }

        while (!dq.empty() && dq.front() == 0)
            dq.pop_front();

        if (dq.empty())
            return "0";

        while (!dq.empty()) {
            ans += to_string(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};
```
