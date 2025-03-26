
class Solution {
    public:
      pair<bool, pair<int, int>> func(Node* root){
          pair<bool, pair<int, int>> left, right, res = {true, {root->data, root->data}};
          if(root->left){
              left = func(root->left);
              res = {res.first && left.first && left.second.second<root->data, {min(res.second.first, left.second.first), max(res.second.second, left.second.second)}};
          }
          if(root->right){
              right = func(root->right);
              res = {res.first && right.first && root->data<right.second.first, {min(res.second.first, right.second.first), max(res.second.second, right.second.second)}};
          }
          return res;
      }
      // Function to check whether a Binary Tree is BST or not.
      bool isBST(Node* root) {
          // Your code here
          return func(root).first;
      }
  };
  
  
  