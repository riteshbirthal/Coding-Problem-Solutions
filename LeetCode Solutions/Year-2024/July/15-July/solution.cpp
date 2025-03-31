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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        map<int, TreeNode*> nodes;
        for(int i = 0; i < n; i++){
            nodes[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
        }
        TreeNode* root;
        for(int i = 0; i < n; i++){
            if(nodes.find(descriptions[i][0])==nodes.end()){
                nodes[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
                root = nodes[descriptions[i][0]];
            }
        }
        for(int i = 0; i < n; i++){
            if(descriptions[i][2]){
                nodes[descriptions[i][0]]->left = nodes[descriptions[i][1]];
            }else{
                nodes[descriptions[i][0]]->right = nodes[descriptions[i][1]];;
            }
        }
        return root;
    }
};