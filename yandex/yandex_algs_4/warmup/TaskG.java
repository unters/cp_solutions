package warmup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class TaskG {
    public static void main(String[] args) throws IOException {
        int n, m;
        int[][] grid;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] nm = br.readLine().split(" ");
            n = Integer.parseInt(nm[0]);
            m = Integer.parseInt(nm[1]);
            grid = new int[n][m];
            for (int i = 0; i < n; ++i) {
                String[] row = br.readLine().split(" ");
                for (int j = 0; j < m; ++j) {
                    grid[i][j] = Integer.parseInt(row[j]);
                }
            }
        }

        int[][] dpLeft = new int[n][m];
        int[][] dpTop = new int[n][m];
        for (int y = 0; y < n; ++y) {
            dpLeft[y][0] = (grid[y][0] == 1) ? 1 : -1;
            for (int x = 1; x < m; ++x) {
                if (grid[y][x] == 1) {
                    dpLeft[y][x] = (dpLeft[y][x - 1] != -1) ? dpLeft[y][x - 1] + 1 : 1;
                }
            }
        }
        for (int x = 0; x < m; ++x) {
            dpTop[0][x] = (grid[0][x] == 1) ? 1 : -1;
            for (int y = 1; y < n; ++y) {
                if (grid[y][x] == 1) {
                    dpTop[y][x] = (dpTop[y - 1][x] != -1) ? dpTop[y - 1][x] + 1 : 1;
                }
            }
        }

        int maxSide = 0;
        int[][] dp = new int[n][m];
        for (int x = 0; x < m; ++x) {
            dp[0][x] = (grid[0][x] == 1) ? 1 : 0;
            maxSide = Math.max(maxSide, dp[0][x]);
        }
        for (int y = 0; y < n; ++y) {
            dp[y][0] = (grid[y][0] == 1) ? 1 : 0;
            maxSide = Math.max(maxSide, dp[y][0]);
        }
        for (int y = 1; y < n; ++y) {
            for (int x = 1; x < m; ++x) {
                dp[y][x] = Math.min(dp[y - 1][x - 1] + 1, Math.min(dpLeft[y][x], dpTop[y][x]));
                maxSide = Math.max(maxSide, dp[y][x]);
            }
        }

        System.out.println(maxSide);
    }
}
