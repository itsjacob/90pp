class Solution
{
public:
  int findNumberOfLIS(vector<int> &nums)
  {
    // dp_len stores the length of longest increasing subsequence ending with the number nums[ii]
    // dp_ccnt stores the number of longest increasing subsequence ending with the number nums[ii]
    std::vector<int> dp_len(nums.size(), 1);
    std::vector<int> dp_cnt(nums.size(), 1);
    for (int ii = 1; ii < dp_len.size(); ii++) {
      for (int jj = ii - 1; jj >= 0; jj--) {
        if (nums[ii] <= nums[jj]) continue;
        if (dp_len[jj] + 1 == dp_len[ii]) {
          // already met the max len before
          dp_cnt[ii] += dp_cnt[jj];
        } else if (dp_len[ii] < dp_len[jj] + 1) {
          // first time meet the max len
          dp_len[ii] = dp_len[jj] + 1;
          dp_cnt[ii] = dp_cnt[jj];
        }
      }
    }
    int lenOflongestSubsequence = *std::max_element(begin(dp_len), end(dp_len));
    int res{ 0 };
    for (int ii = 0; ii < dp_len.size(); ii++) {
      if (dp_len[ii] == lenOflongestSubsequence) {
        res += dp_cnt[ii];
      }
    }
    return res;
  }
};
