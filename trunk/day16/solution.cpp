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

#define findBottomLeftValue findBottomLeftValue_bfs

class Solution
{
public:
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
