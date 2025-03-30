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
    int func(TreeNode* root, unordered_map<int, int>& u, map<int, priority_queue<int>>& lh, unordered_map<int, int>& nh, int level){
        if(!root) return 0;
        int left = func(root->left, u, lh, nh, level+1);
        int right = func(root->right, u, lh, nh, level+1);
        int height = 1 + max(left, right);
        u[root->val] = level;
        nh[root->val] = height;
        lh[level].push(height);
        return height;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> vec;
        map<int, priority_queue<int>> level_heights;
        unordered_map<int, int> u, node_height;
        priority_queue<int> pq;
        int level, height, temp_h;
        height = func(root, u, level_heights, node_height, 0);
        temp_h = height;
        for(auto q : queries){
            level = u[q];
            pq = level_heights[level];
            if(pq.size()==1){
                height -= node_height[q];
            }else{
                if(node_height[q]==pq.top()){
                    pq.pop();
                    height += pq.top() - node_height[q];
                }
            }
            vec.push_back(height-1);
            height = temp_h;
        }
        return vec;
    }
};