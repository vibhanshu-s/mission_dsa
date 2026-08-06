# 387. First Unique Character in a String

**Difficulty:** Easy · **Language:** C++ · **Memory:** 14.7 MB · **Runtime:** 8 ms

[View on LeetCode](https://leetcode.com/problems/first-unique-character-in-a-string/)

**Tags:** `Hash Table`, `String`, `Queue`, `Counting`

> Accepted 2026-08-06 · synced automatically by CodeSync

## Problem

Given a string `s`, find the **first** non-repeating character in it and return its index. If it **does not** exist, return `-1`.

**Example 1:**

**Input:** s = "leetcode"

**Output:** 0

**Explanation:**

The character `'l'` at index 0 is the first character that does not occur at any other index.

**Example 2:**

**Input:** s = "loveleetcode"

**Output:** 2

**Example 3:**

**Input:** s = "aabb"

**Output:** -1

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of only lowercase English letters.

## Solution

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        for(int i=0;i<s.size();i++)
            if(freq[s[i]-'a']==1) 
                return i;
        return -1;
    }
};
```
