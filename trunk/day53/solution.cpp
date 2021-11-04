/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree *root)
{
  int minCol{ INT_MAX };
  int maxCol{ -INT_MAX };
  std::unordered_map<int, int> aMap;
  std::queue<std::pair<Tree *, int>> aQueue;
  aQueue.emplace(root, 0);
  while (!aQueue.empty()) {
    int qSize = aQueue.size();
    for (int ii = 0; ii < qSize; ii++) {
      Tree *aNode = aQueue.front().first;
      int col = aQueue.front().second;
      aQueue.pop();
      if (!aMap.count(col)) {
        aMap[col] = aNode->val;
      }
      minCol = std::min(minCol, col);
      maxCol = std::max(maxCol, col);
      if (aNode->left != nullptr) {
        aQueue.emplace(aNode->left, col - 1);
      }
      if (aNode->right != nullptr) {
        aQueue.emplace(aNode->right, col + 1);
      }
    }
  }
  std::vector<int> res;
  for (int ii = minCol; ii <= maxCol; ii++) {
    if (aMap.count(ii)) {
      res.push_back(aMap[ii]);
    }
  }
  return res;
}
