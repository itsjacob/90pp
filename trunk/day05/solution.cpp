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
    while (!mystack.empty()) {
      mystack_helper.push(mystack.top());
      mystack.pop();
    }
    int res = mystack_helper.top();
    mystack_helper.pop();
    while (!mystack_helper.empty()) {
      mystack.push(mystack_helper.top());
      mystack_helper.pop();
    }
    return res;
  }

  /** Get the front element. */
  int peek()
  {
    while (!mystack.empty()) {
      mystack_helper.push(mystack.top());
      mystack.pop();
    }
    int res = mystack_helper.top();
    while (!mystack_helper.empty()) {
      mystack.push(mystack_helper.top());
      mystack_helper.pop();
    }
    return res;
  }

  /** Returns whether the queue is empty. */
  bool empty() { return mystack.empty(); }

private:
  std::stack<int> mystack;
  std::stack<int> mystack_helper;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
