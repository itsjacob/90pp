class Solution
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int sumOfNums = std::accumulate(nums.begin(), nums.end(), 0);
    sumOfNums = std::abs(sumOfNums);
    if (target < -sumOfNums || target > sumOfNums) return 0;

    int nSum = 2 * sumOfNums + 1;
    std::vector<int> dp0(nSum, 0);
    std::vector<int> dp1(nSum, 0);
    dp0[nums[0] + sumOfNums] += 1;
    dp0[-nums[0] + sumOfNums] += 1;

    for (int jj = 1; jj < nums.size(); jj++) {
      int num = nums[jj];
      std::fill(dp1.begin(), dp1.end(), 0);
      for (int ii = 0; ii < nSum; ii++) {
        if (ii + num < nSum) {
          dp1[ii + num] += dp0[ii];
        }
        if (ii - num >= 0) {
          dp1[ii - num] += dp0[ii];
        }
      }
      dp0 = dp1;
    }
    return dp0[target + sumOfNums];
  }
};
