class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int sumOfNums = std::accumulate(nums.begin(), nums.end(), 0);
    if (sumOfNums % 2 != 0) return false;
    int halfSum = sumOfNums / 2;
    // dp[jj][ii] represents the the total value from first jj nums given our bag capacity is ii
    std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(halfSum + 1, 0));
    for (int jj = 1; jj <= nums.size(); jj++) {
      for (int ss = 1; ss <= halfSum; ss++) {
        if (nums[jj - 1] > ss) {
          // current num exceeds the bag capacity
          dp[jj][ss] = dp[jj - 1][ss];
        } else {
          // pack as much as we can
          dp[jj][ss] = std::max(dp[jj - 1][ss - nums[jj - 1]] + nums[jj - 1], dp[jj - 1][ss]);
        }
      }
    }
    return dp[nums.size()][halfSum] == halfSum;
  }
};
