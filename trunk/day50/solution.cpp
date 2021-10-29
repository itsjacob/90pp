class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    // use a visited array of the same size as grid
    int m = grid.size();
    int n = grid[0].size();
    std::vector<std::vector<bool>> visited(m);
    for (int jj = 0; jj < m; jj++) {
      visited[jj] = std::vector<bool>(n, false);
    }

    int res{ 0 };
    for (int jj = 0; jj < m; jj++) {
      for (int ii = 0; ii < n; ii++) {
        if (visited[jj][ii] || grid[jj][ii] == 0) continue;
        dfs(grid, jj, ii, visited, res);
      }
    }
    return res;
  }

private:
  void dfs(std::vector<std::vector<int>> &grid, int jj, int ii, std::vector<std::vector<bool>> &visited, int &res)
  {
    int count{ 0 };
    dfs_helper(grid, jj, ii, visited, count);
    res = std::max(res, count);
  }

  void dfs_helper(std::vector<std::vector<int>> &grid, int jj, int ii, std::vector<std::vector<bool>> &visited,
                  int &count)
  {
    if (visited[jj][ii]) return;
    visited[jj][ii] = true;
    count++;
    if (jj < grid.size() - 1 && grid[jj + 1][ii] != 0) {
      dfs_helper(grid, jj + 1, ii, visited, count);
    }
    if (jj > 0 && grid[jj - 1][ii] != 0) {
      dfs_helper(grid, jj - 1, ii, visited, count);
    }
    if (ii < grid[0].size() - 1 && grid[jj][ii + 1] != 0) {
      dfs_helper(grid, jj, ii + 1, visited, count);
    }
    if (ii > 0 && grid[jj][ii - 1] != 0) {
      dfs_helper(grid, jj, ii - 1, visited, count);
    }
    return;
  }
};
