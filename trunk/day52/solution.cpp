int solve(vector<vector<int>> &graph, int target)
{
  // BFS approach starting from the target vertex
  // target is also the index in the adjacency list
  std::unordered_set<int> visited(graph.size());
  std::queue<int> aQueue;
  int res{ -1 };
  aQueue.push(target);
  int depth{ 0 };
  while (!aQueue.empty()) {
    int qSize = aQueue.size();
    depth++;
    for (int ii = 0; ii < qSize; ii++) {
      int curVertex = aQueue.front();
      aQueue.pop();
      for (auto const &neighbor : graph[curVertex]) {
        if (neighbor == target) {
          return depth;
        }
        if (visited.count(neighbor)) continue;
        visited.insert(neighbor);
        aQueue.push(neighbor);
      }
    }
  }
  return -1;
}
