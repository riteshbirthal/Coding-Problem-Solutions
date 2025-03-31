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
    pair<int, vector<int>> func(TreeNode* root, int d){
        if(!root) return {0, vector<int>(d, 0)};
        pair<int, vector<int>> left, right, ans;
        left = func(root->left, d);
        right = func(root->right, d);
        vector<int> vec(d, 0);
        cout << "Node " << root->val << endl;
        for(int i = 1; i < d; i++){
            vec[i] = left.second[i-1] + right.second[i-1];
            cout << vec[i] << " " ;
        }
        cout << endl;
        if(!root->left && !root->right) vec[0] = 1;
        ans = {left.first + right.first, vec};
        for(int i = 1; i < d; i++){
            for(int j = 1; j <= d-i; j++){
                ans.first += left.second[i-1]*right.second[j-1];
            }
        }
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        return func(root, distance).first;
    }
};