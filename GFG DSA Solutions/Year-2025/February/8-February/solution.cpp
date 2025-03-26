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
      vector<int> mergeVectors(vector<int>& vec, vector<int>& v){
          for(int x : v)
              vec.push_back(x);
          return vec;
      }
      
      void leftTraversal(Node* root, vector<int>& left){
          if(!root) return ;
          left.push_back(root->data);
          root->left ? leftTraversal(root->left, left) : leftTraversal(root->right, left);
          return ;
      }
      
      void leafTraversal(Node* root, vector<int>& leaf){
          if(!root) return ;
          if(!root->left && !root->right)
              leaf.push_back(root->data);
          leafTraversal(root->left, leaf);
          leafTraversal(root->right, leaf);
          return ;
      }
      
      void rightTraversal(Node* root, vector<int>& right){
          if(!root) return ;
          root->right ? rightTraversal(root->right, right) : rightTraversal(root->left, right);
          right.push_back(root->data);
          return ;
      }
      
      vector<int> boundaryTraversal(Node *root) {
          if(!root->left && !root->right)
              return {root->data};
          vector<int> left, leaf, right, res = {root->data};
          leftTraversal(root->left, left);
          if(left.size())
              left.pop_back();
              
          leafTraversal(root, leaf);
          
          rightTraversal(root->right, right);
          if(right.size()){
              reverse(right.begin(), right.end());
              right.pop_back();
          }
          if(right.size())
              reverse(right.begin(), right.end());
          res = mergeVectors(res, left);
          res = mergeVectors(res, leaf);
          res = mergeVectors(res, right);
          return res;
      }
  };