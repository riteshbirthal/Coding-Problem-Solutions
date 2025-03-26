/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    public:
      void func(Node* root, vector<int>& res){
          if(!root) return ;
          func(root->left, res);
          res.push_back(root->data);
          func(root->right, res);
      }
      // Function to return a list containing the inorder traversal of the tree.
      vector<int> inOrder(Node* root) {
          // Your code here
          vector<int> res;
          func(root, res);
          return res;
      }
  };