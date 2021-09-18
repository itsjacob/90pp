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
  ListNode *swapPairs(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode dummy(0, head);
    ListNode *p0{ &dummy };
    ListNode *p1{};
    ListNode *p2{};
    while (p0->next != nullptr && p0->next->next != nullptr) {
      p1 = p0->next;
      p2 = p1->next;
      // change 0->1->2->3 t0 0->1->3, 2->3
      p1->next = p2->next;
      // change 0->1->3, 2->3 to 0->1, 2->1->3
      p2->next = p1;
      // change 0->, 2->1->3 to 0->2->1->3
      p0->next = p2;
      // Move p0 two steps forward
      p0 = p1;
    }
    return dummy.next;
  }
};
