class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    // one only walks down
    for (int ii = 0; ii < m; ii++) {
      dp[ii][0] = 1;
    }
    // one only walks right
    for (int jj = 0; jj < n; jj++) {
      dp[0][jj] = 1;
    }
    // (ii, jj) position can only be reached from above or the left
    for (int ii = 1; ii < m; ii++) {
      for (int jj = 1; jj < n; jj++) {
        dp[ii][jj] = dp[ii - 1][jj] + dp[ii][jj - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};
