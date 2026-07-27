/*
 * HackerRank - Candies
 * https://www.hackerrank.com/contests/h-cs3p-10-07-2026/challenges/candies/problem
 *
 * Problem: Give each child at least 1 candy. Any child with a higher
 *          rating than a neighbor must get more candies than that
 *          neighbor. Minimize the total candies distributed.
 *
 * Approach: Two-pass greedy.
 *   1. Left-to-right pass: if arr[i] > arr[i-1], candies[i] = candies[i-1] + 1
 *      (satisfies the "left neighbor" constraint).
 *   2. Right-to-left pass: if arr[i] > arr[i+1], candies[i] = max(candies[i],
 *      candies[i+1] + 1) (satisfies the "right neighbor" constraint without
 *      breaking what pass 1 already guaranteed).
 *   3. Sum all candies.
 *
 * Time  : O(n)
 * Space : O(n)
 */

import java.io.*;
import java.util.*;

public class Candies {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);

        st.nextToken();
        int n = (int) st.nval;

        int[] ratings = new int[n];
        for (int i = 0; i < n; i++) {
            st.nextToken();
            ratings[i] = (int) st.nval;
        }

        int[] candies = new int[n];
        Arrays.fill(candies, 1);

        // Left to right: enforce "higher rating than left neighbor -> more candies"
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left: enforce "higher rating than right neighbor -> more candies"
        long total = candies[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
            total += candies[i];
        }

        System.out.println(total);
    }
}
