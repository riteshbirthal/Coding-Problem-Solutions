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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> vec;
        queue<TreeNode*> q;
        int s, idx;
        q.push(root);
        TreeNode* node;
        while(!q.empty()){
            s = q.size();
            vec.push_back(0);
            idx = vec.size()-1;
            for(int i = 0; i < s; i++){
                node = q.front();
                q.pop();
                vec[idx] += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        sort(vec.begin(), vec.end());
        if(vec.size()<k) return -1;
        return vec[idx-k+1];
    }
};