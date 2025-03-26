/*
struct Node {
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
      int func(Node* root, int k, unordered_map<int, int> & u, int currSum){
          if(!root)
              return 0;
          currSum += root->data;
          int res = u.find(currSum-k)==u.end() ? 0 : u[currSum-k];
          u.find(currSum)==u.end() ? u[currSum] = 1 : u[currSum]++;
          res += func(root->left, k, u, currSum);
          res += func(root->right, k, u, currSum);
          u[currSum]==1 ? u.erase(currSum) : u[currSum]--;
          return res;
      }
      
      int sumK(Node *root, int k) {
          // code here
          unordered_map<int, int> u;
          u[0] = 1;
          return func(root, k, u, 0);
      }
  };