class Solution
{
public:
  int numTrees(int n)
  {
    // subtrees have duplicates, so memoization can help
    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, 0));
    return helper(1, n, memo);
  }

private:
  int helper(int beg, int end, std::vector<std::vector<int>> &memo)
  {
    if (beg > end) return 1;
    if (memo[beg][end] != 0) return memo[beg][end];
    int res{ 0 };
    for (int ii = beg; ii <= end; ii++) {
      // with root node value ii, recursively count how many left/right subtrees there are
      // the number of trees with root node value ii is cross product of left/right subtrees
      auto leftTrees = helper(beg, ii - 1, memo);
      auto rightTrees = helper(ii + 1, end, memo);
      res += leftTrees * rightTrees;
    }
    memo[beg][end] = res;
    return res;
  }
};
