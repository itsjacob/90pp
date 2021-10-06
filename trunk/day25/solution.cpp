class Solution
{
public:
  ListNode *middleNode(ListNode *head)
  {
    ListNode *pSlow{ head };
    ListNode *pFast{ head };
    while (pFast != nullptr && pFast->next != nullptr) {
      pFast = pFast->next->next;
      pSlow = pSlow->next;
    }
    return pSlow;
  }
};
