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
        TreeNode* constructTree(vector<int>& preorder, int start1, int last1, vector<int>& postorder, int start2, int last2){
            if(start1>last1 || start2>last2)
                return NULL;
            TreeNode* root = new TreeNode(preorder[start1]);
            if(start1==last1){
                return root;
            }
            if(preorder[start1+1]==postorder[last2-1]){
                root->left = constructTree(preorder, start1 + 1, last1, postorder, start2, last2 - 1);
            }else{
                int idx1 = start1 + 1, idx2 = last2 - 1;
                while(idx2>=start2 && preorder[start1+1]!=postorder[idx2])
                    idx2--;
                while(idx1<=last1 && postorder[last2-1]!=preorder[idx1])
                    idx1++;
                root->left = constructTree(preorder, start1+1, idx1-1, postorder, start2, idx2);
                root->right = constructTree(preorder, idx1, last1, postorder, idx2+1, last2-1);
            }
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = preorder.size();
            return constructTree(preorder, 0, n-1, postorder, 0, n-1);
        }
    };