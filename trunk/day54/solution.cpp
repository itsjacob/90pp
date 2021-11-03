class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    std::vector<int> dp(cost.size() + 1, 0);
    for (int ii = 2; ii < dp.size(); ii++) {
      dp[ii] = std::min(dp[ii - 1] + cost[ii - 1], dp[ii - 2] + cost[ii - 2]);
    }
    return dp[dp.size() - 1];
  }
};
