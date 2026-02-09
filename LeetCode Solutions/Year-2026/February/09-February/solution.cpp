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
    void func(TreeNode* root, vector<TreeNode*>& vec){
        if(!root) 
            return ;
        func(root->left, vec);
        vec.push_back(root);
        func(root->right, vec);
        return ;
    }

    TreeNode* func2(vector<TreeNode*>& vec, int l, int r){
        if(l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root = vec[mid];
        vec[mid]->left = func2(vec, l, mid-1);
        vec[mid]->right = func2(vec, mid+1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vec;
        func(root, vec);
        int n = vec.size();
        return func2(vec, 0, n-1);
    }
};
