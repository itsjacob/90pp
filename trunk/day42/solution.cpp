class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    int left{ 0 };
    int right = grid.size() * grid[0].size();
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (isBottomRightReachable(grid, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

private:
  bool isBottomRightReachable(vector<vector<int>> &grid, int mid)
  {
    // Treat the grid as a graph, each grid element is a vertex, edges exist when one can swim from one
    // element to another
    // DFS traverse the graph, store the visited vertices in a hashtable
    // check the bottom right vertex is in the hashtable or not
    std::unordered_set<int> res;
    std::stack<int> aStack;
    if (grid[0][0] <= mid) {
      aStack.emplace(0);
    }

    std::vector<std::pair<int, int>> dirs{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while (!aStack.empty()) {
      auto me = aStack.top();
      aStack.pop();
      res.emplace(me);
      // Early break
      if (res.find(grid.size() * grid.size() - 1) != res.end()) return true;
      int row = me / grid.size();
      int col = me - row * grid.size();
      for (auto const &dir : dirs) {
        int neighborRow = row + dir.first;
        int neighborCol = col + dir.second;
        int neighbor = neighborRow * grid.size() + neighborCol;
        if (neighborRow < 0 || neighborRow >= grid.size() || neighborCol < 0 || neighborCol >= grid.size() ||
            grid[neighborRow][neighborCol] > mid || res.count(neighbor))
          continue;
        aStack.emplace(neighbor);
      }
    }
    return (res.find(grid.size() * grid.size() - 1) != res.end());
  }
};
