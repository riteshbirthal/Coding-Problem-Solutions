/*
Node is as follows
class Node {
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
      void func(Node* root, vector<int>& vec){
          if(!root) return ;
          func(root->left, vec);
          vec.push_back(root->data);
          func(root->right, vec);
          return ;
      }
      
      bool findTarget(Node *root, int target) {
          // your code here.
          vector<int> vec;
          func(root, vec);
          unordered_set<int> u(vec.begin(), vec.end());
          for(int x : vec){
              if(2*x == target)
                  continue;
              if(u.find(target-x)!=u.end())
                  return true;
          }
          return false;
      }
  };