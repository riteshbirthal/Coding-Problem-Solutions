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
class FindElements {
    TreeNode* rootNode;
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while(!q.empty()){
            node = q.front(), q.pop();
            if(node->left){
                node->left->val = 2*node->val + 1;
                q.push(node->left);
            }
            if(node->right){
                node->right->val = 2*node->val + 2;
                q.push(node->right);
            }
        }
        rootNode = root;
    }
    
    bool find(int target) {
        bool res = false;
        queue<TreeNode*> q;
        q.push(rootNode);
        TreeNode* node;
        while(!q.empty() && !res){
            node = q.front(), q.pop();
            if(node->val>target)
                continue;
            if(node->val==target)
                res = true;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return res;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */