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
    void getMaxSum(TreeNode* root, int level, vector<int>& levelSum){
        if(!root)
            return ;
        if(levelSum.size()==level)
            levelSum.push_back(0);
        levelSum[level] += root->val;
        getMaxSum(root->left, level+1, levelSum);
        getMaxSum(root->right, level+1, levelSum);
        return ;
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> levelSum;
        getMaxSum(root, 0, levelSum);
        int res = 0, mx = INT_MIN, n = levelSum.size();
        for(int i = 0; i < n; i++)
            if(levelSum[i]>mx)
                mx = levelSum[i], res = i+1;
        return res;
    }
};
