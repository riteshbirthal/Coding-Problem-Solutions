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
    int getTotal(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root)
            return 0;
        int sum = root->val;
        sum += getTotal(root->left, dp);
        sum += getTotal(root->right, dp);
        dp[root] = sum;
        return sum;
    }

    long long getMax(TreeNode* root, int total, unordered_map<TreeNode*, int>& dp){
        if(!root)
            return 0;
        long long res = (long long)(total - dp[root]) * (long long)dp[root];
        return max(res, max(getMax(root->left, total, dp), getMax(root->right, total, dp)));
    }

    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        int total = getTotal(root, dp);
        long long res = getMax(root, total, dp), MOD = 1e9+7;
        return res%MOD;
    }
};
