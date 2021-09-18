/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) { return sortedListToBST_(head, nullptr); }

private:
  TreeNode *sortedListToBST_(ListNode *head, ListNode *tail)
  {
    // the list contains nodes in the range of [head, tail);
    // When do we stop? - when the head and tail meet
    if (head == tail) {
      // No element in the range: leaf node that has no left/right children
      return nullptr;
    }
    // Find the middle ListNode of the subtree
    ListNode *pSlow{ head };
    ListNode *pFast{ head };
    while (pFast != tail && pFast->next != tail) {
      pFast = pFast->next->next;
      pSlow = pSlow->next;
    }

    TreeNode *subroot = new TreeNode(pSlow->val);
    subroot->left = sortedListToBST_(head, pSlow);
    subroot->right = sortedListToBST_(pSlow->next, tail);
    return subroot;
  }
};
