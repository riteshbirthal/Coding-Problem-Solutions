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
        vector<int> largestValues(TreeNode* root) {
            vector<int> res;
            queue<TreeNode*> q;
            if(root) q.push(root);
            int k, mx;
            while(q.size()){
                k = q.size(), mx = INT_MIN;
                for(int i = 0; i < k; i++){
                    root = q.front(), q.pop();
                    mx = max(mx, root->val);
                    if(root->left) q.push(root->left);
                    if(root->right) q.push(root->right);
                }
                res.push_back(mx);
            }
            return res;
        }
    };