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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q, prevQ;
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()){
            prevQ = q;
            int k = q.size();
            while(k--){
                root = q.front(), q.pop();
                if(root->left){
                    parent[root->left] = root;
                    q.push(root->left);
                }
                if(root->right){
                    parent[root->right] = root;
                    q.push(root->right);
                }
            }
        }
        q = prevQ;
        set<TreeNode*> st;
        while(q.size()>1){
            int k = q.size();
            while(k--){
                root = q.front(), q.pop();
                st.insert(parent[root]);
            }
            for(auto x = st.begin(); x != st.end(); x++)
                q.push(*x);
            st.clear();
        }
        return q.front();
    }
};
