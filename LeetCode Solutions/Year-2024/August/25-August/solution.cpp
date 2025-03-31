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
    void func(TreeNode* root, vector<int>& vec){
        if(!root) return ;
        func(root->left, vec);
        func(root->right, vec);
        vec.push_back(root->val);
        return ;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        func(root, vec);
        return vec;
    }
};