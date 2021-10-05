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
  int sumNumbers(TreeNode *root)
  {
    std::stack<std::pair<TreeNode *, int>> stackOfNodes;
    stackOfNodes.emplace(root, root->val);
    int sum{ 0 };
    while (!stackOfNodes.empty()) {
      TreeNode *aNode = stackOfNodes.top().first;
      int partialSum = stackOfNodes.top().second;
      stackOfNodes.pop();
      if (aNode->left == nullptr && aNode->right == nullptr) {
        // Leaf node, sum it's value
        sum += partialSum;
        continue;
      }
      partialSum *= 10;
      if (aNode->right != nullptr) {
        stackOfNodes.emplace(aNode->right, partialSum + aNode->right->val);
      }
      if (aNode->left != nullptr) {
        stackOfNodes.emplace(aNode->left, partialSum + aNode->left->val);
      }
    }
    return sum;
  }
};
