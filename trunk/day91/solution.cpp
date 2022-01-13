class Node
{
public:
  int val;
  Node *next;
  Node *down;
  Node(int val_, Node *next_, Node *down_)
      : val{ val_ }
      , next{ next_ }
      , down{ down_ } {};
};

class Skiplist
{
public:
  Skiplist()
  {
    // head node is a dummy node
    head = new Node(-1, nullptr, nullptr);
  }

  bool search(int target)
  {
    bool res{ false };
    Node *curr = head;
    while (curr) {
      // check the next pointer so that we can still move down before we reach the end of the linkedlist of the level
      while (curr->next && curr->next->val < target) curr = curr->next;
      if (curr->next && curr->next->val == target) return true;
      curr = curr->down;
    }
    return false;
  }

  void add(int num)
  {
    // find each lower_bound - 1 Node from each level and push them into the vector
    std::stack<Node *> aStack;
    Node *curr = head;
    while (curr) {
      while (curr->next && curr->next->val < num) curr = curr->next;
      aStack.push(curr);
      curr = curr->down;
    }
    // insert the new node into the bottom list, and probabilistically insert to upper layers if necessary
    Node *down = nullptr;
    bool needInsert{ true };
    while (needInsert && !aStack.empty()) {
      curr = aStack.top();
      aStack.pop();
      curr->next = new Node(num, curr->next, down);
      // down pointer is the newly createdly Node if we need it in the upper layer Linkedlist
      down = curr->next;
      needInsert = (rand() % 2) == 0;
    }
    // Do we need to create a new layer of head?
    if (needInsert) {
      head = new Node(-1, nullptr, head);
    }
    return;
  }

  bool erase(int num)
  {
    bool found{ false };
    Node *curr = head;
    while (curr) {
      while (curr->next && curr->next->val < num) curr = curr->next;
      if (curr->next && curr->next->val == num) {
        found = true;
        curr->next = curr->next->next;
      }
      curr = curr->down;
    }
    return found;
  }

private:
  Node *head;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
