class Solution
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.size() == 1) return nums[0];
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int ii = 2; ii < dp.size(); ii++) {
      dp[ii] = std::max(dp[ii - 1], dp[ii - 2] + nums[ii]);
    }
    return dp[nums.size() - 1];
  }
};
