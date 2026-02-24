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
    int getSum(TreeNode* root, int num){
        if(!root->left && !root->right)
            return num*2 + root->val;
        int res = 0;
        if(root->left)
            res += getSum(root->left, num*2 + root->val);
        if(root->right)
            res += getSum(root->right, num*2 + root->val);
        return res;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return getSum(root, 0);
    }
};
