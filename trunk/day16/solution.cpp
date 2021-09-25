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

#define findBottomLeftValue findBottomLeftValue_dfs
//#define findBottomLeftValue findBottomLeftValue_bfs

class Solution
{
private:
  int dfs_res;
  int maxDepth{ 0 };
  void dfs(TreeNode *subroot, int curDepth)
  {
    if (subroot == nullptr) return;
    if (curDepth > maxDepth) {
      maxDepth = curDepth;
      dfs_res = subroot->val;
    }
    if (subroot->left != nullptr) {
      dfs(subroot->left, curDepth + 1);
    }
    if (subroot->right != nullptr) {
      dfs(subroot->right, curDepth + 1);
    }
    return;
  }

public:
  int findBottomLeftValue_dfs(TreeNode *root)
  {
    dfs(root, 1);
    return dfs_res;
  }

  int findBottomLeftValue_bfs(TreeNode *root)
  {
    std::queue<TreeNode *> theQueue;
    theQueue.push(root);
    TreeNode *res;
    while (!theQueue.empty()) {
      int sz = theQueue.size();
      res = theQueue.front();
      for (int ii = 0; ii < sz; ii++) {
        TreeNode *theNode = theQueue.front();
        theQueue.pop();
        if (theNode->left != nullptr) {
          theQueue.push(theNode->left);
        }
        if (theNode->right != nullptr) {
          theQueue.push(theNode->right);
        }
      }
    }
    return res->val;
  }
};
