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
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.empty()) return nullptr;
    // if the list in the vector container is single element, then this is basically merge sort
    // which takes O(KlogK)
    // becase the element in the vector can be of size N, so the total cost is O(NKlogK) since we need to walk
    // through each element within the list when we do divide-and-conquer each time
    return helper(lists, 0, lists.size() - 1);
  }

private:
  ListNode *helper(vector<ListNode *> lists, int beg, int end)
  {
    if (beg > end) return nullptr;
    if (beg == end) return lists[beg];
    int mid = beg + (end - beg) / 2;
    auto left = helper(lists, beg, mid);
    auto right = helper(lists, mid + 1, end);
    ListNode *lHead{ left };
    ListNode *rHead{ right };
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    while (lHead != nullptr && rHead != nullptr) {
      if (lHead->val < rHead->val) {
        p->next = lHead;
        lHead = lHead->next;
      } else {
        p->next = rHead;
        rHead = rHead->next;
      }
      p = p->next;
    }
    while (lHead != nullptr) {
      p->next = lHead;
      p = p->next;
      lHead = lHead->next;
    }
    while (rHead != nullptr) {
      p->next = rHead;
      p = p->next;
      rHead = rHead->next;
    }
    p = dummy->next;
    delete dummy;
    return p;
  }
};
