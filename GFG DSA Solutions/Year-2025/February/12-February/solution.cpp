/*Complete the function below

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
      void func(Node* root, vector<int>& vec){
          if(!root) return ;
          func(root->left, vec);
          vec.push_back(root->data);
          func(root->right, vec);
          return ;
      }
      // Return the Kth smallest element in the given BST
      int kthSmallest(Node *root, int k) {
          // add code here.
          vector<int> vec;
          func(root, vec);
          return vec.size()<k ? -1 : vec[k-1];
      }
  };