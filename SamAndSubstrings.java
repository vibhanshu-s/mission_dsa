/*
 * HackerRank - Sam and substrings
 * https://www.hackerrank.com/contests/h-cs3p-17-07-2026/challenges/sam-and-substrings/problem
 *
 * Problem: Given a numeric string, sum the integer values of ALL of its
 *          substrings, modulo 1_000_000_007.
 *
 * Approach: O(n) digit-contribution DP.
 *   Let dp[i] = sum of all substrings that END at index i (0-indexed).
 *   Every substring ending at i-1 can be extended by digit[i] to form a
 *   substring ending at i: newValue = oldValue * 10 + digit[i].
 *   There are exactly (i+1) substrings ending at index i (one starting at
 *   each position 0..i), so the digit[i] contribution is added (i+1) times.
 *
 *   dp[i] = dp[i-1] * 10 + digit[i] * (i+1)      (all mod MOD)
 *
 *   The final answer is the sum of dp[0..n-1], mod MOD.
 *
 * Time  : O(n)
 * Space : O(1) extra (besides the input string)
 */

import java.io.*;

public class SamAndSubstrings {

    private static final long MOD = 1_000_000_007L;

    public static int substrings(String n) {
        long dpPrev = 0;
        long answer = 0;

        for (int i = 0; i < n.length(); i++) {
            int digit = n.charAt(i) - '0';
            long dpCurrent = (dpPrev * 10 + (long) digit * (i + 1)) % MOD;
            answer = (answer + dpCurrent) % MOD;
            dpPrev = dpCurrent;
        }

        return (int) answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String n = br.readLine().trim();

        System.out.println(substrings(n));
    }
}
