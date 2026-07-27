/*
 * HackerRank - Consecutive Subsequences
 * https://www.hackerrank.com/contests/h-cs3p-10-07-2026/challenges/consecutive-subsequences/problem
 *
 * Problem: Count the number of consecutive subsequences (subarrays) whose
 *          sum is divisible by k.
 *
 * Approach: Prefix sums mod k.
 *   - Let prefix[0] = 0 and prefix[i] = a[1] + a[2] + ... + a[i].
 *   - A subarray (i, j] has sum divisible by k if and only if
 *     prefix[j] % k == prefix[i] % k.
 *   - So we count, for each remainder r in [0, k-1], how many prefix sums
 *     share that remainder, and sum up C(count, 2) pairs -- done here by
 *     accumulating "freq[mod] so far" as we scan left to right.
 *
 * Time  : O(n) per test case
 * Space : O(k)
 */

import java.io.*;
import java.util.*;

public class ConsecutiveSubsequences {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);

        st.nextToken();
        int t = (int) st.nval;

        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            st.nextToken();
            int n = (int) st.nval;
            st.nextToken();
            int k = (int) st.nval;

            long[] freq = new long[k];
            freq[0] = 1; // prefix sum of 0 (empty prefix) has remainder 0

            long runningSum = 0;
            long answer = 0;

            for (int i = 0; i < n; i++) {
                st.nextToken();
                int val = (int) st.nval;

                runningSum += val;
                int mod = (int) (runningSum % k);

                answer += freq[mod];
                freq[mod]++;
            }

            sb.append(answer).append('\n');
        }

        System.out.print(sb);
    }
}
