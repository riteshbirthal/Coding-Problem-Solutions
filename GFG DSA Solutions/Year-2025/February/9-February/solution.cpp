// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    public:
      pair<int, int> func(Node* root){
          if(!root->left && !root->right)
              return {root->data, root->data};
          pair<int, int> left = {-1e8, -1e8}, right = {-1e8, -1e8}, res;
          if(root->left)
              left = func(root->left);
          if(root->right)
              right = func(root->right);
          vector<int> vec = {left.first, root->data + left.second, right.first, root->data + right.second, root->data + left.second + right.second, left.second, right.second};
          res = {*max_element(vec.begin(), vec.end()), root->data + max(0, max(left.second, right.second))};
          return res;
      }
      // Function to return maximum path sum from any node in a tree.
      int findMaxSum(Node *root) {
          // code here
          pair<int, int> pr = func(root);
          return max(pr.first, pr.second);
      }
  };