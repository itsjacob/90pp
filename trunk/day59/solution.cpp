class Solution
{
public:
  double knightProbability(int n, int k, int row, int column)
  {
    if (k == 0) return 1.0;
    // Time evolution of the check bord dp[k][j][i]
    // dp[k][j][i] is the total possible paths that we land to position (j, i) at time step k
    // dp[k][j][i] := sum(dp[k-1][y][x]), for (y,x) as neighbors of (j, i)
    std::vector<std::pair<int, int>> dirs{ { -1, -2 }, { -1, 2 }, { 1, -2 }, { 1, 2 },
                                           { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 } };
    std::vector<std::vector<double>> dp_prev(n, std::vector<double>(n, 1));
    for (int kk = 0; kk < k; kk++) {
      std::vector<std::vector<double>> dp_curr(n, std::vector<double>(n, 0));
      for (int jj = 0; jj < n; jj++) {
        for (int ii = 0; ii < n; ii++) {
          for (auto const &dir : dirs) {
            int y = jj + dir.second;
            int x = ii + dir.first;
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            dp_curr[jj][ii] += dp_prev[y][x];
          }
        }
      }
      dp_prev = dp_curr;
    }
    return dp_prev[row][column] / std::pow(8, k);
  }
};
