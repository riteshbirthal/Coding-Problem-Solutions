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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if((!root1 && root2) || (root1 && !root2) || (root1->val!=root2->val)) return false;
        bool ans = true;
        if((root1->left && root2->left && root1->left->val!=root2->left->val) || (root1->right && root2->right && root1->right->val!=root2->right->val) || (root1->left && !root2->left) || (root1->right && !root2->right)){
            TreeNode* left = root1->left;
            root1->left = root1->right;
            root1->right = left;
        }
        ans = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        return ans;
    }
};