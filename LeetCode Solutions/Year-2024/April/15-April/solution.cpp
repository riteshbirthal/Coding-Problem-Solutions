/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int func(TreeNode* root, int curr_num){
        if(root->left==NULL && root->right==NULL){
            return curr_num*10 + root->val;
        }
        int ans = 0;
        if(root->left) ans += func(root->left, curr_num*10 + root->val);
        if(root->right) ans += func(root->right, curr_num*10 + root->val);
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        return func(root, 0);
    }
};