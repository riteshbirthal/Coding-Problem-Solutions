/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    int ans;
    void func(Node* root, int currNum){
        if(!root) return ;
        if(!root->left && !root->right){
            ans += currNum*10 + root->data;
            return ;
        }
        if(root->left)
            func(root->left, currNum*10 + root->data);
        if(root->right)
            func(root->right, currNum*10 + root->data);
        return ;
    }
    
    int treePathsSum(Node *root) {
        // code here.
        ans = 0;
        func(root, 0);
        return ans;
    }
};
