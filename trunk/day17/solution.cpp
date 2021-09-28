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
  void serialize_preorder(TreeNode *subroot, std::stringstream &theStream)
  {
    if (subroot == nullptr) {
      theStream << "null ";
      return;
    }
    theStream << subroot->val << " ";
    serialize_preorder(subroot->left, theStream);
    serialize_preorder(subroot->right, theStream);
    return;
  }

  TreeNode *deserialize_preorder(std::istringstream &theStream)
  {
    std::string theStr;
    theStream >> theStr;
    if (theStr == "null") return nullptr;
    TreeNode *root = new TreeNode(std::stoi(theStr));
    root->left = deserialize_preorder(theStream);
    root->right = deserialize_preorder(theStream);
    return root;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (root == nullptr) return "null";
    // pre-order traversal and dump node values to stringstream then convert to string
    std::stringstream theStream;
    serialize_preorder(root, theStream);
    return theStream.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    std::istringstream theStream(data);
    return deserialize_preorder(theStream);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
