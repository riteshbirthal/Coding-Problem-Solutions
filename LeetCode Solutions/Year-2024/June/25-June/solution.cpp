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
    int sum;
    int sum_fun(TreeNode* root){
        if(!root) return 0;
        return sum_fun(root->left) + root->val + sum_fun(root->right);
    }
    TreeNode* bToG(TreeNode* root){
        if(!root) return NULL;
        root->left = bToG(root->left);
        int temp = root->val;
        root->val = sum;
        sum = sum - temp;
        root->right = bToG(root->right);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        sum = sum_fun(root);
        root = bToG(root);
        return root;
    }
};