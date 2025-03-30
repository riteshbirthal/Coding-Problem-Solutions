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
    void levelSumFunc(TreeNode* root, vector<int>& vec){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        int k, l;
        while(!q.empty()){
            k = q.size();
            vec.push_back(0);
            l = vec.size()-1;
            for(int i = 0; i < k; i++){
                node = q.front(), q.pop();
                vec[l] += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
    }

    TreeNode* replaceValue(TreeNode* root, vector<int>& vec, int level){
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        if(level==vec.size()) return root;
        int sum = 0;
        if(root->left) sum += root->left->val;
        if(root->right) sum += root->right->val;
        if(root->left){
            root->left->val = vec[level] - sum;
            root->left = replaceValue(root->left, vec, level+1);
        }
        if(root->right){
            root->right->val = vec[level] - sum;
            root->right = replaceValue(root->right, vec, level+1);
        }
        return root;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> vec;
        levelSumFunc(root, vec);
        root = replaceValue(root, vec, 1);
        root->val = 0;
        return root;
    }
};