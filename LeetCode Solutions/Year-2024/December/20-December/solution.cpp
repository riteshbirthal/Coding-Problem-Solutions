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
        void levelTraversal(TreeNode* root, vector<vector<TreeNode*>> &vec){
            vector<TreeNode*> curr, temp;
            curr.push_back(root);
            int n = curr.size();
            while(n){
                vec.push_back(curr);
                temp = {};
                for(int i = 0; i < n; i++){
                    if(curr[i]->left || curr[i]->right){
                        temp.push_back(curr[i]->left);
                        temp.push_back(curr[i]->right);
                    }
                }
                curr = temp;
                n = curr.size();
            }
            return ;
        }
        TreeNode* reverseOddLevels(TreeNode* root) {
            vector<vector<TreeNode*>> vec;
            levelTraversal(root, vec);
            int n = vec.size(), left, right, element;
            for(int i = 1; i < n; i += 2){
                left = 0, right = vec[i].size()-1;
                while(left<right){
                    element = vec[i][left]->val;
                    vec[i][left]->val = vec[i][right]->val;
                    vec[i][right]->val = element;
                    left++, right--;
                }
            }
            return root;
        }
    };