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
        TreeNode* recoverFromPreorder(string traversal) {
            if(!traversal.size())
                return NULL;
            string left = "", right = "", val = "";
            int idx = 0, n = traversal.size(), count;
            while(idx<n && traversal[idx]!='-'){
                val += traversal[idx];
                idx++;
            }
            TreeNode* root = new TreeNode(stoi(val));
            bool flag = true;
            while(idx<n){
                count = 0;
                while(idx<n && traversal[idx]=='-')
                    count++, idx++;
                if(count==1 && flag)
                    flag = false;
                else if(count==1){
                    idx--;
                    break;
                }
                for(int i = 1; i < count; i++)
                    left += '-';
                while(idx<n && traversal[idx]!='-')
                    left += traversal[idx], idx++;
            }
            while(idx<n){
                count = 0;
                while(idx<n && traversal[idx]=='-')
                    count++, idx++;
                for(int i = 1; i < count; i++)
                    right += '-';
                while(idx<n && traversal[idx]!='-')
                    right += traversal[idx], idx++;
            }
            root->left = recoverFromPreorder(left);
            root->right = recoverFromPreorder(right);
            return root;
        }
    };