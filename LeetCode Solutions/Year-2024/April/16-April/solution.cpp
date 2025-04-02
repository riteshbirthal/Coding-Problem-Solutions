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
    TreeNode* func(TreeNode* root, int val, int depth, int curr_depth, int left){
        if(curr_depth==depth){
            TreeNode* root_new = new TreeNode(val);
            if(left) root_new->left = root;
            else root_new->right = root;
            return root_new;
        }
        if(root->left==NULL && root->right==NULL && curr_depth==depth-1){
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            return root;
        }
        if(root->left) root->left = func(root->left, val, depth, curr_depth+1, 1);
        if(root->right) root->right = func(root->right, val, depth, curr_depth+1, 0);
        if(root->left==NULL && curr_depth==depth-1){
            root->left = new TreeNode(val);
        }
        if(root->right==NULL && curr_depth==depth-1){
            root->right = new TreeNode(val);
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return func(root, val, depth, 1, 1);
    }
};