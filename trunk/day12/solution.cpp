class LRUCache
{
  class ListNode
  {
  public:
    int key;
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int key_, int val_)
        : key{ key_ }
        , val{ val_ }
        , prev{ nullptr }
        , next{ nullptr }
    {}
    ListNode(int key_, int val_, ListNode *prev_, ListNode *next_)
        : key{ key_ }
        , val{ val_ }
        , prev(prev_)
        , next(next_)
    {}
  };

  class DoublyLinkedList
  {
  private:
    ListNode *dummyHead;
    ListNode *dummyTail;
    ListNode *head;
    ListNode *tail;

    /*
     * @brief Remove a node from the doubly linked list, and set it's next/prev pointers to null
     * @param ListNode  the node to be removed from the list
     */
    void removeNode(ListNode *theNode)
    {
      if (theNode->prev == dummyHead && theNode->next == dummyTail) {
        // Remove single node list
        head = tail = nullptr;
      } else if (theNode->prev == dummyHead) {
        // Remove head node
        head = theNode->next;
      } else if (theNode->next == dummyTail) {
        // Remove tail node
        tail = theNode->prev;
      }
      theNode->prev->next = theNode->next;
      theNode->next->prev = theNode->prev;
      theNode->next = nullptr;
      theNode->prev = nullptr;
    }

  public:
    DoublyLinkedList()
        : head(nullptr)
        , tail(nullptr)
    {
      dummyHead = new ListNode(-1, -1, nullptr, nullptr);
      dummyTail = new ListNode(-2, -2, nullptr, nullptr);
      dummyHead->next = dummyTail;
      dummyTail->prev = dummyHead;
    }

    DoublyLinkedList(ListNode *head_, ListNode *tail_)
        : head(head_)
        , tail(tail_)
    {
      dummyHead = new ListNode(-1, -1, nullptr, head);
      head->prev = dummyHead;
      dummyTail = new ListNode(-2, -2, tail, nullptr);
      tail->next = dummyTail;
    }

    ~DoublyLinkedList()
    {
      ListNode *p{ dummyHead };
      while (p != nullptr) {
        ListNode *toDelete = p;
        p = p->next;
        delete toDelete;
      }
    }

    ListNode *front() const { return head; }

    ListNode *back() const { return tail; }

    void push_front(ListNode *newNode)
    {
      newNode->next = dummyHead->next;
      newNode->next->prev = newNode;
      dummyHead->next = newNode;
      newNode->prev = dummyHead;
      head = newNode;
      if (head->next == dummyTail) tail = head;
    }

    void pop_back()
    {
      if (tail == nullptr) return;
      ListNode *theNode = tail;
      removeNode(tail);
      delete theNode;
    }

    void moveNodeToFront(ListNode *theNode)
    {
      removeNode(theNode);
      push_front(theNode);
    }
  };

private:
  std::unordered_map<int, ListNode *> mapKey2Node;
  DoublyLinkedList dList;
  int capacity;

public:
  LRUCache(int capacity_)
      : capacity{ capacity_ }
  {}

  int get(int key)
  {
    auto theNodeIter = mapKey2Node.find(key);
    if (theNodeIter == mapKey2Node.end()) return -1;
    ListNode *theNode = theNodeIter->second;
    dList.moveNodeToFront(theNode);
    return theNode->val;
  }

  void put(int key, int value)
  {
    auto theNodeIter = mapKey2Node.find(key);
    if (theNodeIter != mapKey2Node.end()) {
      // key already in the Cache, we simply update it
      ListNode *theNode = theNodeIter->second;
      theNode->val = value;
      dList.moveNodeToFront(theNode);
    } else {
      // key not in the Cache, create a Node, add to map, add to doubly linked list
      ListNode *theNode = new ListNode(key, value);
      if (mapKey2Node.size() == capacity) {
        // remove the tail Node from the map
        mapKey2Node.erase(dList.back()->key);
        // remove the least recently used node from the tail of the list
        dList.pop_back();
      }
      // Add the new node to the map
      mapKey2Node.emplace(key, theNode);
      // Add the most recently used one node to the front of the list
      dList.push_front(theNode);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
