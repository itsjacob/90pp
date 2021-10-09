class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    // pair<outEdge, inEdge>
    std::vector<std::pair<int, int>> edgeCounts(n + 1, std::make_pair(0, 0));
    for (auto const ti : trust) {
      edgeCounts[ti[0]].first++;
      edgeCounts[ti[1]].second++;
    }
    for (int ii = 1; ii <= n; ii++) {
      if (edgeCounts[ii].first == 0 && edgeCounts[ii].second == n - 1) {
        return ii;
      }
    }
    return -1;
  }
};
