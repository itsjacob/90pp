class Solution
{
public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes)
  {
    // create the graph with adjancenty list
    std::vector<std::vector<int>> adjList(n + 1);
    for (auto const &dislike : dislikes) {
      adjList[dislike[0]].push_back(dislike[1]);
      // undirected graph so update both vertices
      adjList[dislike[1]].push_back(dislike[0]);
    }

    // 0: uncolored; 1: group 1 color; 2: group 2 color
    std::vector<int> colors(n + 1, 0);
    for (int ii = 1; ii <= n; ii++) {
      if (colors[ii] == 0) {
        if (!dfs(adjList, colors, ii, 1)) return false;
      }
    }
    return true;
  }

private:
  // @return  whether the vertex and its neighbors can be colored into two categories
  bool dfs(std::vector<std::vector<int>> &adjList, std::vector<int> &colors, int cur, int color)
  {
    colors[cur] = color;
    for (auto const &neighbor : adjList[cur]) {
      // conflicts in neighors
      if (colors[neighbor] == color) {
        return false;
      }
      // uncolored neighbor, color it with a different color
      if (colors[neighbor] == 0) {
        if (!dfs(adjList, colors, neighbor, -color)) return false;
      }
    }
    return true;
  }
};
