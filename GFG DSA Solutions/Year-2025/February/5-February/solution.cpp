/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
      // Function to convert a binary tree into its mirror tree.
      void mirror(Node* node) {
          // code here
          if(!node) return ;
          Node* left = node->left;
          node->left = node->right;
          node->right = left;
          mirror(node->left);
          mirror(node->right);
          return ;
      }
  };
  