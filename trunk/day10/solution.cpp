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
  ListNode *getIntersectionNode_Slow(ListNode *headA, ListNode *headB)
  {
    // O(n^2) solution
    ListNode *pHeadA{ headA };
    while (pHeadA != nullptr) {
      ListNode *pHeadB{ headB };
      while (pHeadB != nullptr) {
        if (pHeadA == pHeadB) {
          return pHeadA;
        }
        pHeadB = pHeadB->next;
      }
      pHeadA = pHeadA->next;
    }
    return nullptr;
  }

  ListNode *getIntersectionNode_FastAuxSpace(ListNode *headA, ListNode *headB)
  {
    // O(n) time and O(n) space complexities solution using a dictionary
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode dummyA(0, headA);
    ListNode dummyB(0, headB);
    std::unordered_map<ListNode *, int> mydict;
    ListNode *pA = &dummyA;
    ListNode *pB = &dummyB;
    while (pA->next != nullptr) {
      mydict.emplace(pA->next, 1);
      pA = pA->next;
    }
    while (pB->next != nullptr) {
      auto findRes = mydict.find(pB->next);
      if (findRes != mydict.end()) {
        return findRes->first;
      }
      pB = pB->next;
    }
    return nullptr;
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    // O(n) time and O(1) space complexities
    // fast/slow two-pointer problem, actually same pace but different distance walkers
    // The first time two pointers will meet is when they walk the same amount of distance
    // Walker A walked lengthA = skipA + commonLen, after it reaches the end of list A
    // Walker B walked lengthB = skipB + commonLen, after it reaches the end of list B
    // If walker A walks additional skipB, and walker B walks additional skipA,
    // they will have their first meet at the total distance skipA + commonLen + skipB
    // The the trick is walking both pointers at the same pace, until their first meet if they can meet,
    // otherwise, they will all end up with nullptr at the end of their lists
    ListNode *pA{ headA };
    ListNode *pB{ headB };
    while (pA != pB) {
      // walk another skipB for walker A
      if (pA == nullptr)
        pA = headB;
      else
        pA = pA->next;
      // walk another skipA for walker B
      if (pB == nullptr)
        pB = headA;
      else
        pB = pB->next;
    }
    return pA;
  }
};
