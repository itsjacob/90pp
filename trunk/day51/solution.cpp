class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    // find the maximum depth away from the land vertices
    // use all land as starting vertices and expand from them
    std::queue<std::pair<int, int>> aQueue;
    int n = grid.size();
    for (int jj = 0; jj < n; jj++) {
      for (int ii = 0; ii < n; ii++) {
        if (grid[jj][ii] == 0) continue;
        aQueue.push({ jj, ii });
      }
    }

    // pruning
    if (aQueue.size() == 0 || aQueue.size() == n * n) return -1;

    std::vector<std::pair<int, int>> dirs{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    int depth{ 0 };
    while (!aQueue.empty()) {
      int nsize = aQueue.size();
      depth++;
      for (int ii = 0; ii < nsize; ii++) {
        auto me = aQueue.front();
        aQueue.pop();
        // grid[me.first][me.second] = depth;
        for (auto &dir : dirs) {
          int row = me.first + dir.first;
          int col = me.second + dir.second;
          if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] != 0) continue;
          // Set the neigboring depth here to avoid adding the same neighbors from different vertices
          grid[row][col] = depth;
          aQueue.emplace(row, col);
        }
      }
    }
    return depth - 1;
  }
};
