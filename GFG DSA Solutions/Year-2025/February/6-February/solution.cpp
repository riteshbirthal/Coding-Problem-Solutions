// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    public:
      Node* func(vector<int>& pre, int p, vector<int>& in, int l, int r){
          if(p==pre.size() || l>r) return NULL;
          int flag = 0, idx = -1;
          for(int i = l; i <= r; i++)
              if(in[i]==pre[p]) flag = 1, idx = i;
          if(flag==0) return NULL;
          Node* root = new Node(pre[p]);
          root->left = func(pre, p+1, in, l, idx-1);
          root->right = func(pre, p+idx-l+1, in, idx+1, r);
          return root;
      }
      // Function to build the tree from given inorder and preorder traversals
      Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
          // code here
          return func(preorder, 0, inorder, 0, inorder.size()-1);
      }
  };