
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
      Node* LCA(Node* root, Node* n1, Node* n2) {
          // code here
          int n1Side, n2Side;
          if(n1->data==root->data || n2->data==root->data)
              return root;
          n1Side = n1->data < root->data ? -1 : 1;
          n2Side = n2->data < root->data ? -1 : 1;
          if(n1Side*n2Side==-1)
              return root;
          else if(n1Side==-1)
              return LCA(root->left, n1, n2);
          else
              return LCA(root->right, n1, n2);
      }
  };
  
  
  