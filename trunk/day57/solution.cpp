class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int m = text1.size();
    int n = text2.size();
    // dp[i][j] stores the lcs of text1 up to i-th char and text2 up to j-th char
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          // this char exist in the lcs
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          // the char doesn't exist in the lcs
          // value obtained from previous steps
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};
