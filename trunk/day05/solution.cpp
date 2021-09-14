class MyQueue
{
public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { mystack.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    // Always get the item from cache
    // if we cache is empty, we dump the items from mystack in reverse order
    if (mystack_cache.empty()) {
      while (!mystack.empty()) {
        mystack_cache.push(mystack.top());
        mystack.pop();
      }
    }
    int res = mystack_cache.top();
    mystack_cache.pop();
    return res;
  }

  /** Get the front element. */
  int peek()
  {
    if (mystack_cache.empty()) {
      while (!mystack.empty()) {
        mystack_cache.push(mystack.top());
        mystack.pop();
      }
    }
    return mystack_cache.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return mystack.empty() && mystack_cache.empty(); }

private:
  std::stack<int> mystack;
  std::stack<int> mystack_cache;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
