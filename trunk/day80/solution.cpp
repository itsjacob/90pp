class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    if (candidates.empty()) return {};
    vector<vector<int>> res;
    vector<int> comb;
    int sum{ 0 };
    backtrack(res, comb, candidates, 0, target, sum);
    return res;
  }

  void backtrack(vector<vector<int>> &res, vector<int> &comb, vector<int> const &candidates, int start, int target,
                 int &sum)
  {
    if (sum == target) {
      res.emplace_back(comb);
      return;
    }
    if (sum > target) {
      return;
    }
    for (int ii = start; ii < candidates.size(); ii++) {
      comb.push_back(candidates[ii]);
      sum += candidates[ii];
      backtrack(res, comb, candidates, ii, target, sum);
      sum -= candidates[ii];
      comb.pop_back();
    }
  }
};
