/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{

private:
  void bfs(TreeNode *root, std::stringstream &theStream)
  {
    // attach nullptr as leaf nodes' left/right child
    // level-order travael of the complete binary tree
    std::queue<std::pair<TreeNode *, int>> aQueue;
    aQueue.emplace(root, 0);
    int maxNodeNum{ 1 };
    while (!aQueue.empty()) {
      int sz = aQueue.size();
      int prevNodeIdx{ 0 };
      int currNodeIdx{ 0 };
      TreeNode *currNode{ nullptr };
      for (int ii = 0; ii < sz; ii++) {
        currNode = aQueue.front().first;
        currNodeIdx = aQueue.front().second;
        aQueue.pop();
        if (prevNodeIdx < currNodeIdx) {
          theStream << "n" << currNodeIdx - prevNodeIdx << ",";
        }
        theStream << currNode->val << ",";
        if (currNode->left) {
          aQueue.emplace(currNode->left, currNodeIdx * 2);
        }
        if (currNode->right) {
          aQueue.emplace(currNode->right, currNodeIdx * 2 + 1);
        }
        prevNodeIdx = currNodeIdx + 1;
      }
      if (currNodeIdx < maxNodeNum - 1) {
        theStream << "n" << maxNodeNum - 1 - currNodeIdx << ",";
      }
      // Next level increse the number number by x2
      maxNodeNum *= 2;
    }
    return;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (root == nullptr) return "null";
    // level traversal and dump node values to stringstream then convert to string
    std::stringstream theStream;
    bfs(root, theStream);
    string res = theStream.str();
    res.pop_back();
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data == "null") return nullptr;
    // O(n) space solution for converting string into array
    std::vector<TreeNode *> theVec;
    std::unordered_map<int, TreeNode *> theMap;
    std::string delimiter{ "," };
    // int const DELIM_INT_VAL{1024};
    int idx{ 0 };
    size_t beg{ 0 };
    size_t end{ data.find(delimiter) };
    while (end != std::string::npos) {
      std::string token = data.substr(beg, end - beg);
      if (token[0] == 'n') {
        idx += std::stoi(token.substr(1));
      } else {
        theMap.emplace(idx, new TreeNode(std::stoi(token)));
        idx++;
      }
      beg = end + delimiter.length();
      end = data.find(delimiter, beg);
    }
    // do it for the last element
    std::string token = data.substr(beg, end - beg);
    if (token[0] == 'n') {
      idx += std::stoi(token.substr(1));
    } else {
      theMap.emplace(idx, new TreeNode(std::stoi(token)));
      idx++;
    }

    for (int ii = 0; ii < idx; ii++) {
      int leftChildIdx = ii * 2 + 1;
      int rightChildIdx = leftChildIdx + 1;
      if (theMap.count(leftChildIdx) > 0) {
        theMap[ii]->left = theMap[leftChildIdx];
      }
      if (theMap.count(rightChildIdx) > 0) {
        theMap[ii]->right = theMap[rightChildIdx];
      }
    }
    return theMap[0];
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
