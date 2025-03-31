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
    TreeNode* func(TreeNode* root, unordered_set<int>& nodes, vector<TreeNode*>& vec){
        if(!root) return NULL;
        if(nodes.find(root->val)!=nodes.end()){
            TreeNode* left, *right;
            left = func(root->left, nodes, vec);
            right = func(root->right, nodes, vec);
            if(left) vec.push_back(left);
            if(right) vec.push_back(right);
            return NULL;
        }
        root->left = func(root->left, nodes, vec);
        root->right = func(root->right, nodes, vec);
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> nodes;
        int n = to_delete.size();
        for(int i = 0; i < n; i++)
            nodes.insert(to_delete[i]);
        root = func(root, nodes, ans);
        if(root) ans.push_back(root);
        return ans;
    }
};