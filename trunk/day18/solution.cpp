/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  // The # of nodes in the tree is in range [1, 1000], so bfs is out of the discussion due to int overflow
  // dfs and record a map of (key, val) = (col, vector<pair<row, TreeNode.val>>), record min/max col, then sort within
  // each map[col] with two keys(row, TreeNode.val)
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    std::vector<vector<int>> res;
    std::unordered_map<int, std::vector<std::pair<int, int>>> resMap;
    std::stack<std::tuple<TreeNode *, int, int>> aStack;
    aStack.emplace(root, 0, 0);
    resMap.emplace(0, std::vector<std::pair<int, int>>());
    int minCol{ 0 };
    int maxCol{ 0 };
    while (!aStack.empty()) {
      TreeNode *aNode = std::get<0>(aStack.top());
      int col = std::get<1>(aStack.top());
      int row = std::get<2>(aStack.top());
      aStack.pop();
      minCol = std::min(minCol, col);
      maxCol = std::max(maxCol, col);
      if (resMap.count(col) == 0) {
        resMap.emplace(col, std::vector<std::pair<int, int>>());
      }
      resMap[col].emplace_back(row, aNode->val);
      if (aNode->right != nullptr) aStack.emplace(aNode->right, col + 1, row + 1);
      if (aNode->left != nullptr) aStack.emplace(aNode->left, col - 1, row + 1);
    }

    auto comp = [](std::pair<int, int> &p1, std::pair<int, int> &p2) -> bool {
      return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
    };
    for (int ii = minCol, idx = 0; ii <= maxCol; ii++) {
      if (resMap.count(ii) > 0) {
        if (resMap.size() > 1) {
          std::sort(resMap[ii].begin(), resMap[ii].end(), comp);
        }
        res.push_back(std::vector<int>());
        for (auto const &vv : resMap[ii]) {
          res[idx].push_back(vv.second);
        }
        idx++;
      }
    }

    // for (auto const &m : resMap) {
    //   cout << "key, val = " << m.first << ", [";
    //   for (auto const &vi : m.second) {
    //     cout << vi.second << ", ";
    //   }
    //   cout << "]" << endl;
    // }

    // cout << "[";
    // for (auto const &m : res) {
    //   cout << "[";
    //   for (auto const &vi : m) {
    //     cout << vi << ", ";
    //   }
    //   cout << "]";
    // }
    // cout << "]" << endl;
    return res;
  }
};
