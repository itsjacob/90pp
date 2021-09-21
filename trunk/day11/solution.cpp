/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *pSlow{ head };
    ListNode *pFast{ head };
    while (pFast != nullptr && pFast->next != nullptr) {
      pFast = pFast->next->next;
      pSlow = pSlow->next;
      if (pSlow == pFast) break;
    }

    if (pFast == nullptr || pFast->next == nullptr) {
      return nullptr;
    }

    pSlow = head;
    while (pSlow != pFast) {
      pSlow = pSlow->next;
      pFast = pFast->next;
    }
    return pSlow;
  }
};
