# Time Conversion

**Difficulty:** Easy · **Language:** cpp20 · **Group:** Algorithms · **Max score:** 15 · **Score:** 1.0

[View on HackerRank](https://www.hackerrank.com/challenges/time-conversion/problem)

**Tags:** `Algorithms`, `Warmup`

> Accepted 2026-09-02 · synced automatically by CodeSync

## Problem

Given a time in [-hour AM/PM format](https://en.wikipedia.org/wiki/12-hour_clock), convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
 - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

**Example**

- Return '12:01:00'.
- Return '00:01:00'.

**Function Description**

Complete the  function with the following parameter(s):

- : a time in  hour format

**Returns**

- : the time in  hour format

**Input Format**

A single string  that represents a time in -hour clock format (i.e.:  or ).

**Constraints**

- All input times are valid

**Sample Input 0**

```
07:05:45PM
```

**Sample Output 0**

```
19:05:45
```

## Solution

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int n = s.size();
    string ans(s.begin(),s.end()-2);
    if(s[n-2]=='P' && s[0]=='1' && s[1]=='2')
        return ans;
    else if(s[n-2]=='A'&& s[0]!=1 && s[1]!='2')
        return ans;
    else if(s[n-2]=='A'){
        ans[1]='0';
        ans[0]='0';
        return ans;
   }
    else {
        string hr(s.begin(),s.begin()+2);
        int k = stoi(hr);
        k+=12;
        hr = to_string(k);
        ans[0]=hr[0];
        ans[1]=hr[1];
        return ans;
   }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
```
