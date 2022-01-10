class Solution
{
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    if (candidates.empty()) return {};
    vector<vector<int>> res;
    vector<int> comb;
    int sum{ 0 };
    std::sort(begin(candidates), end(candidates));
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
      // tricky conditional to avoid duplicates
      if (ii > start && candidates[ii] == candidates[ii - 1]) continue;
      comb.push_back(candidates[ii]);
      sum += candidates[ii];
      backtrack(res, comb, candidates, ii + 1, target, sum);
      sum -= candidates[ii];
      comb.pop_back();
    }
  }
};
