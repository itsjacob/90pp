class Solution
{
public:
  // Loop over the string
  // Push each char into a stack until we hit ']'
  // When a ']' is encountered, we pop the stack until we hit '['
  // and the popped chars are stored in temporary container,
  // We then find out how many times we need to repeated the popped chars,
  // remove the repeat number from the stack, and push back n times of the chars in the temporary container
  // In the end, we have all chars in the stack
  // we iterate through the stack to concatenate the chars in the stack
  string decodeString(string s)
  {
    std::stack<char> resStack;
    for (auto const& c : s) {
      if (c != ']') {
        resStack.push(c);
      } else {
        // Find the chars to be repeated in between '[' and ']'
        std::vector<char> repeatStrVec;
        while (resStack.top() != '[') {
          repeatStrVec.push_back(resStack.top());
          resStack.pop();
        }
        // Remove the '[' from the stack
        resStack.pop();
        // Find the repeat count, and remove the numbers from the stack
        int count{0};
        int base = 1;
        // static_cast is needed as isdigit has undefined behavior for char type
        while (!resStack.empty() && std::isdigit(static_cast<unsigned char>(resStack.top()))) {
          count += base * (resStack.top() - '0');
          base *= 10;
          resStack.pop();
        }
        // Repeat the chars in betwen '[' and ']' count times and push them back to the stack
        for (int ii = 0; ii < count; ii++) {
          for (auto it = repeatStrVec.rbegin(); it != repeatStrVec.rend(); it++) {
            resStack.push(*it);
          }
        }
      }
    }
    // Pre-allocate the string so that we don't need string concatenation
    std::string res(resStack.size(), '*');
    int idx = resStack.size();
    while (!resStack.empty()) {
      res[--idx] = resStack.top();
      resStack.pop();
    }
    return res;
  }
};
