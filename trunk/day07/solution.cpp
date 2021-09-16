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
class Solution
{
public:
  ListNode* rotateRight(ListNode* head, int k)
  {
    // Walk through the linked list once, to get its size n
    // We only need to rotate k % n steps
    // fast/slow two pointer solution
    if (head == nullptr || head->next == nullptr) return head;
    int nNodes{ 0 };
    ListNode* ptr{ head };
    while (ptr != nullptr) {
      nNodes++;
      ptr = ptr->next;
    }
    k = k % nNodes;
    if (k == 0) return head;

    ListNode* pFast{ head };
    for (int ii = 0; ii < k; ii++) {
      pFast = pFast->next;
    }

    ListNode* pSlow{ head };
    while (pFast->next != nullptr) {
      pSlow = pSlow->next;
      pFast = pFast->next;
    }
    ListNode* res = pSlow->next;
    pSlow->next = nullptr;
    pFast->next = head;
    return res;
  }
};
