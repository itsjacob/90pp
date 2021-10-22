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
    while (!aStack.empty()) {
      auto me = aStack.top();
      aStack.pop();
      res.emplace(me);
      int row = me / grid.size();
      int col = me - row * grid.size();
      for (int ii = -1; ii <= 1; ii += 2) {
        int neighbor_col = col + ii;
        int neighbor = row * grid.size() + neighbor_col;
        if (neighbor_col >= 0 && neighbor_col < grid.size() && grid[row][neighbor_col] <= mid &&
            res.count(neighbor) == 0) {
          aStack.emplace(neighbor);
        }
      }
      for (int ii = -1; ii <= 1; ii += 2) {
        int neighbor_row = row + ii;
        int neighbor = neighbor_row * grid.size() + col;
        if (neighbor_row >= 0 && neighbor_row < grid.size() && grid[neighbor_row][col] <= mid &&
            res.count(neighbor) == 0) {
          aStack.emplace(neighbor);
        }
      }
    }
    return (res.find(grid.size() * grid.size() - 1) != res.end());
  }
};
