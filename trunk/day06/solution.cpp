class Solution
{
public:
  int maxChunksToSorted(vector<int>& arr)
  {
    // Monotonically ascending stack records the maximum element of ech chunk
    std::stack<int> s;
    for (auto const& ele : arr) {
      if (s.empty() || s.top() <= ele) {
        // ele satisfies the monotonically ascending stack property, add it to the stack
        s.push(ele);
      } else {
        // Adding ele to the stack would break the property,
        // let's find minimum number of relevalent people to resolve it.
        // The relevalent people are those already in the stack and greater than ele.
        // The way to resolve it is that this group of relevalent people together with ele will form a chunk
        // and elect one leader to occupy a position in the stack so the property is still maintained
        // the leader is the maximum number of this chunk, who is the first popped person
        int chunkLeader = s.top();
        s.pop();
        while (!s.empty() && s.top() > ele) {
          s.pop();
        }
        // Now the leader of the chunk is back to the stack
        s.push(chunkLeader);
      }
    }
    return s.size();
  }
};
