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

//#define maxDepth maxDepthRecursive
//#define maxDepth maxDepthIterative_dfs_v1
//#define maxDepth maxDepthIterative_dfs_v2
#define maxDepth maxDepthIterative_bfs

class Solution
{
public:
  int maxDepthIterative_bfs(TreeNode *root)
  {
    if (root == nullptr) return 0;
    // dfs approach
    std::queue<TreeNode *> theNodeQueue;
    std::queue<int> theDepthQueue;
    int curDepth = 1;
    int maxDepth{ 0 };
    theNodeQueue.push(root);
    while (!theNodeQueue.empty()) {
      int nodesOnThisLevel = theNodeQueue.size();
      maxDepth = std::max(maxDepth, curDepth);
      for (int ii = 0; ii < nodesOnThisLevel; ii++) {
        TreeNode *subroot = theNodeQueue.front();
        theNodeQueue.pop();
        if (subroot->left != nullptr) {
          theNodeQueue.push(subroot->left);
        }
        if (subroot->right != nullptr) {
          theNodeQueue.push(subroot->right);
        }
      }
      curDepth++;
    }
    return maxDepth;
  }

  int maxDepthIterative_dfs_v2(TreeNode *root)
  {
    if (root == nullptr) return 0;
    // dfs approach
    std::stack<TreeNode *> theNodeStack;
    std::queue<int> theDepthQueue;
    theNodeStack.push(root);
    theDepthQueue.push(1);
    int maxDepth{ 0 };
    while (!theNodeStack.empty()) {
      TreeNode *subroot = theNodeStack.top();
      theNodeStack.pop();
      int curDepth = theDepthQueue.front();
      theDepthQueue.pop();
      maxDepth = std::max(maxDepth, curDepth);
      if (subroot->left != nullptr) {
        theNodeStack.push(subroot->left);
        theDepthQueue.push(curDepth + 1);
      }
      if (subroot->right != nullptr) {
        theNodeStack.push(subroot->right);
        theDepthQueue.push(curDepth + 1);
      }
    }
    return maxDepth;
  }

  int maxDepthIterative_dfs_v1(TreeNode *root)
  {
    if (root == nullptr) return 0;
    // dfs approach
    std::stack<std::pair<TreeNode *, int>> theStack;
    theStack.emplace(root, 1);
    int maxDepth{ 0 };
    while (!theStack.empty()) {
      TreeNode *subroot = theStack.top().first;
      int curDepth = theStack.top().second;
      maxDepth = std::max(maxDepth, curDepth);
      theStack.pop();
      if (subroot->left != nullptr) {
        theStack.emplace(subroot->left, curDepth + 1);
      }
      if (subroot->right != nullptr) {
        theStack.emplace(subroot->right, curDepth + 1);
      }
    }
    return maxDepth;
  }

  int maxDepthRecursive(TreeNode *root)
  {
    if (root == nullptr) return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return std::max(leftHeight, rightHeight) + 1;
  }
};
