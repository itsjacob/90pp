class Solution
{
public:
  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    vector<vector<int>> res;
    vector<int> permute;
    vector<bool> isVisited(nums.size(), false);
    std::sort(begin(nums), end(nums));
    backtrack(res, permute, isVisited, nums);
    return res;
  }

  void backtrack(vector<vector<int>> &res, vector<int> &permute, vector<bool> &isVisited, vector<int> const &nums)
  {
    if (permute.size() == nums.size()) {
      res.emplace_back(permute);
      return;
    }
    for (int ii = 0; ii < nums.size(); ii++) {
      if (isVisited[ii]) continue;
      // trick third conditional, the first two are the same as combination with duplicates problem
      if (ii > 0 && nums[ii] == nums[ii - 1] && isVisited[ii - 1] == false) continue;
      isVisited[ii] = true;
      permute.push_back(nums[ii]);
      backtrack(res, permute, isVisited, nums);
      permute.pop_back();
      isVisited[ii] = false;
    }
  }
};
