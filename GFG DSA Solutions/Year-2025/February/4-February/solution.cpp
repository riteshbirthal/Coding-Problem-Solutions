/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
    public:
      pair<int, pair<int, int>> func(Node* root){
          if(!root) return {0, {0, 0}};
          pair<int, pair<int, int>> left = func(root->left), right = func(root->right);
          int leftMax = max(left.second.first, left.second.second), rightMax = max(right.second.first, right.second.second);
          return {max(leftMax + rightMax, max(left.first, right.first)), {1 + leftMax, 1 + rightMax}};
      }
      int diameter(Node* root) {
          // Your code here
          return func(root).first;
      }
  };