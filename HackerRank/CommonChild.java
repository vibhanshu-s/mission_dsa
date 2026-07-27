/*
 * HackerRank - Common Child
 * https://www.hackerrank.com/contests/h-cs3p-17-07-2026/challenges/common-child/problem
 *
 * Problem: Given two strings of equal length, find the length of their
 *          longest common child (i.e. longest common subsequence, LCS).
 *
 * Approach: Classic 2D dynamic programming.
 *   dp[i][j] = length of LCS of s1[0..i) and s2[0..j)
 *   - If s1[i-1] == s2[j-1]: dp[i][j] = dp[i-1][j-1] + 1
 *   - Else:                  dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * Time  : O(n * m)  (here n == m, since strings are equal length)
 * Space : O(n * m)
 */

import java.io.*;

public class CommonChild {

    public static int commonChild(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine().trim();
        String s2 = br.readLine().trim();

        System.out.println(commonChild(s1, s2));
    }
}
