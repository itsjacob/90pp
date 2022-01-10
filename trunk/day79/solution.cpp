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
  TreeNode *pruneTree(TreeNode *root)
  {
    // post-order DFS binary tree traversal

    // reach the child of the leaf node
    if (root == nullptr) return nullptr;
    // reassign the pruned left subtree
    root->left = pruneTree(root->left);
    // reassign the pruned right subtree
    root->right = pruneTree(root->right);
    // a pruned left/right subtree should be nullptr if there're no 1's in them
    // if i have all zero left/right subtrees and I'm 0 as well, I can tell my parent to assign me as nullptr
    return (root->val == 0 && root->left == nullptr && root->right == nullptr) ? nullptr : root;
  }
};
