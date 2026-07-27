/*
 * HackerRank - Queen's Attack II
 * https://www.hackerrank.com/contests/h-cs3p-10-07-2026/challenges/queens-attack-2/problem
 *
 * Problem: Count how many squares a queen can attack on an n x n board,
 *          given k obstacles that block her line of sight.
 *
 * Approach: The queen can move in 8 directions: up, down, left, right,
 *           and the 4 diagonals. For each direction, the number of
 *           attackable squares is bounded by whichever is closer:
 *           the edge of the board, or the nearest obstacle in that
 *           direction (exclusive).
 *
 *           1. Compute the 8 board-edge distances directly from n, r_q, c_q.
 *           2. For each obstacle, determine which of the 8 directions it
 *              lies in relative to the queen (same row/column/diagonal),
 *              then shrink that direction's limit if the obstacle is closer.
 *           3. Sum the 8 final limits.
 *
 * Time  : O(k)  (after O(1) setup for the 8 edge distances)
 * Space : O(1)
 */

import java.io.*;
import java.util.*;

public class QueensAttackII {

    // Direction indices
    private static final int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
    private static final int UP_RIGHT = 4, UP_LEFT = 5, DOWN_RIGHT = 6, DOWN_LEFT = 7;

    public static int queensAttack(int n, int k, int r_q, int c_q, int[][] obstacles) {
        int[] limit = new int[8];
        limit[UP] = n - r_q;
        limit[DOWN] = r_q - 1;
        limit[LEFT] = c_q - 1;
        limit[RIGHT] = n - c_q;
        limit[UP_RIGHT] = Math.min(n - r_q, n - c_q);
        limit[UP_LEFT] = Math.min(n - r_q, c_q - 1);
        limit[DOWN_RIGHT] = Math.min(r_q - 1, n - c_q);
        limit[DOWN_LEFT] = Math.min(r_q - 1, c_q - 1);

        for (int[] obs : obstacles) {
            int dr = obs[0] - r_q;
            int dc = obs[1] - c_q;

            if (dc == 0 && dr != 0) {
                // Same column
                if (dr > 0) {
                    limit[UP] = Math.min(limit[UP], dr - 1);
                } else {
                    limit[DOWN] = Math.min(limit[DOWN], -dr - 1);
                }
            } else if (dr == 0 && dc != 0) {
                // Same row
                if (dc > 0) {
                    limit[RIGHT] = Math.min(limit[RIGHT], dc - 1);
                } else {
                    limit[LEFT] = Math.min(limit[LEFT], -dc - 1);
                }
            } else if (Math.abs(dr) == Math.abs(dc)) {
                // Same diagonal
                int dist = Math.abs(dr) - 1;
                if (dr > 0 && dc > 0) {
                    limit[UP_RIGHT] = Math.min(limit[UP_RIGHT], dist);
                } else if (dr > 0 && dc < 0) {
                    limit[UP_LEFT] = Math.min(limit[UP_LEFT], dist);
                } else if (dr < 0 && dc > 0) {
                    limit[DOWN_RIGHT] = Math.min(limit[DOWN_RIGHT], dist);
                } else {
                    limit[DOWN_LEFT] = Math.min(limit[DOWN_LEFT], dist);
                }
            }
            // Obstacles not on the same row, column, or diagonal are irrelevant
        }

        int total = 0;
        for (int l : limit) {
            total += l;
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);

        st.nextToken();
        int n = (int) st.nval;
        st.nextToken();
        int k = (int) st.nval;

        st.nextToken();
        int r_q = (int) st.nval;
        st.nextToken();
        int c_q = (int) st.nval;

        int[][] obstacles = new int[k][2];
        for (int i = 0; i < k; i++) {
            st.nextToken();
            obstacles[i][0] = (int) st.nval;
            st.nextToken();
            obstacles[i][1] = (int) st.nval;
        }

        System.out.println(queensAttack(n, k, r_q, c_q, obstacles));
    }
}
